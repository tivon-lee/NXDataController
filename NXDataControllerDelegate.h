//
//  NXDataControllerDelegate.h
//  NXDataController
//
//  Created by tivon on 16-7-7.
//  Copyright (c) 2016年 tivon. All rights reserved.
//

@class NXDataController;

@protocol NXDataControllerDelegate <NSObject>

@optional

/**
 *  接口将要开始加载
 *
 */
- (void)dataControllerWillStartLoading:(NXDataController *)controller;

/**
 *  接口加载加载成功
 *
 */
- (void)dataControllerDidFinishLoading:(NXDataController *)controller;

/**
 *  接口加载取消
 *
 */
- (void)dataControllerDidCancelLoading:(NXDataController *)controller;

/**
 *  接口加载失败
 *
 */
- (void)dataController:(NXDataController *)controller didFailWithError:(NSError *)error;


@end