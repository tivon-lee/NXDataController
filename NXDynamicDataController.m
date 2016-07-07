//
//  NXDynamicDataController.m
//  NXDataController
//
//  Created by tivon on 16-7-7.
//  Copyright (c) 2016年 tivon. All rights reserved.
//

#import "NXDynamicDataController.h"

@interface NXDynamicDataController ()

@property (nonatomic, copy) NSString *dynamicURLString;

@property (nonatomic, copy) NSString *dynamicRequestMethod;

@end

@implementation NXDynamicDataController

- (instancetype)privateInit
{
    return [super init];
}

+ (instancetype)dataControllerWithURLString:(NSString *)URLString
{
    return [self dataControllerWithURLString:URLString requestMethod:@"GET"];
}

+ (instancetype)dataControllerWithURLString:(NSString *)URLString requestMethod:(NSString *)method
{
    NSParameterAssert([URLString isKindOfClass:[NSString class]]);
    NSParameterAssert([method isKindOfClass:[NSString class]]);
    
    NXDynamicDataController *newInstance = [[NXDynamicDataController alloc] privateInit];
    newInstance.dynamicURLString = URLString;
    newInstance.dynamicRequestMethod = method;
    
    return newInstance;
}

- (NSString *)requestMethod
{
    return self.dynamicRequestMethod;
}

- (NSArray<NSString *> *)requestURLStrings
{
    return @[self.dynamicURLString];
}

@end
