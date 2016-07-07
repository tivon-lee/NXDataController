//
//  NXDataController.h
//  NXDataController
//
//  Created by tivon on 16-7-7.
//  Copyright (c) 2016年 tivon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Mantle/Mantle.h>
#import <AFNetworking/AFNetworking.h>

#import "NXDataControllerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const NXDataControllerErrorDomain;

extern const NSInteger NXDataControllerErrorInvalidObject;

extern NSString * const NXResponseObjectKey;

typedef void (^NXRequestSuccessBlock)(void);

typedef void (^NXRequestFailureBlock)(NSError * _Nullable error);

typedef void (^NXDataControllerLogBlock)(id logObject);

typedef void (^NXTableViewCellConfigureBlock)(UITableViewCell *cell, MTLModel *model);

typedef void (^NXCollectionViewCellConfigureBlock)(UICollectionViewCell *cell, MTLModel *model);

typedef NS_ENUM(NSUInteger, NXMantleObjectListUpdateStyle) {
    NXMantleObjectListUpdateInsert,
    NXMantleObjectListUpdateReplace,
};

@interface NXDataController : NSObject <
NSCopying,
UITableViewDataSource,
UICollectionViewDataSource
>

@property (nullable, nonatomic, weak) id <NXDataControllerDelegate> delegate;

@property (nonatomic, strong, readonly) AFHTTPSessionManager *httpSessionManager;

@property (nonatomic, copy) NXRequestSuccessBlock requestSuccessBlock;

@property (nonatomic, copy) NXRequestFailureBlock requestFailureBlock;

@property (nonatomic, copy, readonly) id responseObject;

// -------------
// Mantle Object
// -------------

@property (nonatomic, strong, nullable) __kindof MTLModel<MTLJSONSerializing> *mantleObject;

@property (nonatomic, strong, nullable) NSMutableArray<__kindof MTLModel *> *mantleObjectList;

@property (nonatomic, assign) NXMantleObjectListUpdateStyle mantleObjectListUpdateStyle;


// -----------
// Data Source
// -----------

@property (nonatomic, copy) NSString *cellIdentifier;

@property (nonatomic, copy) NXTableViewCellConfigureBlock tableViewCellConfigureBlock;

@property (nonatomic, copy) NXCollectionViewCellConfigureBlock collectionViewCellConfigureBlock;

// -----
// Other
// -----

@property (nonatomic, copy) NXDataControllerLogBlock logBlock;

/**
 *  共享实例的方法
 *
 */
+ (instancetype)sharedDataController;


- (instancetype)initWithDelegate:(id <NXDataControllerDelegate>)aDelegate;


// ------------
// 发起请求的方法
// ------------

/**
 *  调用requestWithParams:并传入nil
 */
- (void)request;

/**
 *  发起网络请求
 *
 *  @param params 请求的参数
 */
- (void)requestWithParams:(nullable NSDictionary *)params;

/**
 *  Block风格的接口请求
 *
 *  @param params  请求的参数
 *  @param success 成功的Block
 *  @param failure 失败的Block
 */
- (void)requestWithParams:(nullable NSDictionary *)params
                  success:(nullable NXRequestSuccessBlock)success
                  failure:(nullable NXRequestFailureBlock)failure;

/**
 *  加载更多
 */
- (void)requestMore;

/**
 *  取消当前的接口请求
 */
- (void)cancelRequest;

// ----------------
// 子类需要自定义的方法
// ----------------

/**
 *  HTTP的Method
 */
- (NSString *)requestMethod;

/**
 *  接口请求的地址，可以有多个用于备用重试
 *
 */
- (NSArray<NSString *> *)requestURLStrings;


/**
 *  分页的参数名称
 *
 */
- (NSString *)pageParameterName;

// ----------------
// 请求成功后的处理方法
// ----------------

/**
 *  检测返回的结果是否有效
 *
 */
- (BOOL)isValidWithObject:(id)object;

/**
 *  处理结果的方法
 *
 */
- (void)handleWithObject:(id)object;

// ------------
// Mantle相关方法
// ------------

/**
 *  返回需要转换的Mantle模型类
 *
 *  @return Mantle的Class
 */
- (Class)mantleModelClass;

/**
 *  需要转换的JSON Dictionary位于整个Dictionary中的位置
 *
 *  @return Key Path
 */
- (NSString *)mantleObjectKeyPath;

/**
 *  objectList的键值映射
 *
 *  @return Key Path
 */
- (NSString *)mantleObjectListKeyPath;

/**
 *  指定用于转换到mantleList中的类
 *
 *  @return Mantle的Class
 */
- (Class)mantleListModelClass;


// ----------------
// 完全自定义的相关方法
// ----------------

/**
 *  接口请求成功的处理
 *
 */
- (void)requestOpertaionSuccess:(NSURLSessionDataTask *)task responseObject:(id)responseObject;

/**
 *  接口请求失败的处理
 *
 */
- (void)requestOperationFailure:(NSURLSessionDataTask *)task error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END

