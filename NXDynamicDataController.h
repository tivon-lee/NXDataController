//
//  NXDynamicDataController.h
//  NXDataController
//
//  Created by tivon on 16-7-7.
//  Copyright (c) 2016年 tivon. All rights reserved.
//

#import "NXDataController.h"

@interface NXDynamicDataController : NXDataController

+ (instancetype)dataControllerWithURLString:(NSString *)URLString;

+ (instancetype)dataControllerWithURLString:(NSString *)URLString requestMethod:(NSString *)method;

+ (instancetype)sharedDataController __attribute__((unavailable("Can't use singleton")));

+ (instancetype)new __attribute__((unavailable("Use dataControllerWithURLString: or dataControllerWithURLString:requestMethod: instead.")));

- (instancetype)init __attribute__((unavailable("Use dataControllerWithURLString: or dataControllerWithURLString:requestMethod: instead.")));

@end
