//
//  BOCImageBrowserViewController.h
//  PhotoBrowser
//
//  Created by LeungChaos on 16/7/2.
//  Copyright © 2016年 liang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class BOCImageBrowserViewController;

@protocol BOCImageBrowserViewControllerDelegate <NSObject>

@optional

/**
 *  返回一个需要执行动画的imageView，在打开图片浏览器的时候
 *
 *  @param imageBrowser 图片浏览器对象
 *  @param index        当前显示图片的下标
 *
 *  @return 返回一个与当前图片相对应的UIImageView对象
 *
 *  (如果没有实现这个方法, 或返回值为nil, 就会执行淡入淡出的效果)
 */
- (UIImageView *)imageBrowser:(BOCImageBrowserViewController *)imageBrowser imageViewForStartAnimationAtIndex:(NSInteger)index;

/**
 *  当图片被长按时回调这个方法
 *
 *  (如果不实现，默认就是弹出ActionSheet提示保存图片到相册)
 *
 *  @param iamge        当前显示在浏览器上的图片
 *  @param longPress    长按的UILongPressGestureRecognizer对象
 */
- (void)imageBrowser:(BOCImageBrowserViewController *)imageBrowser image:(UIImage *)iamge didLongPress:(UILongPressGestureRecognizer *)longPress;

@end



@interface BOCImageBrowserViewController : UIViewController

/**
 *  是否显示页码, default is YES;
 */
@property (assign, nonatomic) BOOL showPageLabel;

/**
 *  执行动画需要设置代理
 */
@property (weak, nonatomic) id<BOCImageBrowserViewControllerDelegate> delegate;

/**
 *  便利构造函数，创建图片浏览器
 *
 *  @param datas      需要加载的图片
 *  @param startIndex 从哪一张开始显示
 *  @param isNetwork  是否加载网络图片
 *  @param delegate   成为代理的对象
 *
 *  PS: if isNetwork is YES , datas中的元素为 图片的网络url字符串 , else datas中的元素为 image的文件名(非全路径)
 *
 *  @return BOCImageBrowserViewController对象
 */
- (instancetype)initWithDataSource:(NSArray<NSString *> *)datas startIndex:(NSInteger)startIndex isNetwork:(BOOL)isNetwork delegate:(id<BOCImageBrowserViewControllerDelegate>) delegate;



@end