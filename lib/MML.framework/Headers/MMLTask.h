//
//  MMLTask.h
//  MML
//
//  Created by QingCan on 2019/11/21.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLData.h"
#import "MMLBaseMachine.h"
#import "MMLPerformanceProfiler.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^MMLTaskCompletionBlock) (MMLData * __nullable outputData, NSError * __nullable aError);
typedef void (^MMLTaskPerformanceBlock) (MMLData * __nullable outputData,
                                         MMLPerformanceProfiler * __nullable performanceProfiler,
                                         NSError * __nullable aError);

typedef NS_ENUM(NSInteger, MMLTaskStatus) {
    MMLTaskStatusWaiting = 0,       // 默认状态，正在等待中
    MMLTaskStatusExecuting,         // 执行状态，正在执行中
    MMLTaskStatusCanceled,          // 取消状态，已经被取消
    MMLTaskStatusFinished           // 完成状态，已经执行完成
};

/// 任务封装实体
@interface MMLTask : NSObject
/// 任务标识
@property (nonatomic, copy, readonly) NSString *taskID;
/// 对应的machine
@property (nonatomic, strong, readonly) MMLBaseMachine *machine;
/// 结果回调block
@property (nonatomic, copy, readonly) MMLTaskCompletionBlock taskBlock;
/// 带performance的结果回调block
@property (nonatomic, copy, readonly) MMLTaskPerformanceBlock taskPerformanceBlock;
/// 输入数据
@property (nonatomic, strong, readonly) MMLData *inputData;
/// 任务的执行状态
@property (nonatomic, assign, readonly) MMLTaskStatus taskStatus;

/// 根据inputData创建任务
/// @param machine machine
/// @param inputData 输入数据
/// @param block 回调block
- (instancetype)initTaskWithMachine:(MMLBaseMachine *)machine inputData:(MMLData *)inputData completionBlock:(MMLTaskCompletionBlock)block;

/// 根据inputData创建带performance的任务
/// @param machine machine
/// @param inputData 输入数据
/// @param block performance回调block
- (instancetype)initTaskWithMachine:(MMLBaseMachine *)machine inputData:(MMLData *)inputData performanceBlock:(MMLTaskPerformanceBlock)block;

/// 运行Task
/// @param block 任务是否完成回调
- (void)runTaskWithCompletionBlock:(void(^)(NSError * __nullable error))block;

/// 运行带性能数据的Task
/// @param block 任务是否完成回调
- (void)runPerformanceTaskWithCompletionBlock:(void(^)(NSError * __nullable error))block;

/// 设置status的状态为取消状态
- (void)cancel;
@end

NS_ASSUME_NONNULL_END
