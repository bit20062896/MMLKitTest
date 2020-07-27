//
//  MMLBMLGBDTClassMachine.h
//  MML
//
//  Created by QingCan on 2019/12/16.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLBaseMachine.h"

NS_ASSUME_NONNULL_BEGIN

// 预测结果回调的block
typedef void (^MMLGBDTClassMachineResultBlock)(MMLGBDTMachinePredicateState state, NSString * __nullable predicateResult);

@class MMLOutputData;
@class MMLInputData;
@interface MMLBMLGBDTClassMachine : MMLBaseMachine

#pragma mark - init
/**
 * @brief 初始化machine
 *
 * @param modelURL pb的的地址
 * @param error 错误信息
 * @return self / nil
 */
- (instancetype)initGBDTMachineWithModelURL:(NSString *)modelURL withError:(NSError **)error;

#pragma mark - predicate
/**
 * @brief 异步预测函数
 *
 * @param inputData 输入数据
 * @param resultBlock 预测结果的block回调
 */
- (void)predicateGBDTWithInputData:(MMLInputData *)inputData resultBlock:(MMLGBDTClassMachineResultBlock)resultBlock;

/**
 * @brief 同步预测函数
 *
 * @param inputData 输入数据
 * @param error 预测过程出现的错误
 * @return MMLOutputData 输出数据
 */
- (MMLOutputData *)predicateGBDTWithInputData:(MMLInputData *)inputData error:(NSError **)error;

/// 开启CoreML预测切换
- (void)enableCoreML;

/**
 * @brief 通过模型位置创建model的方法
 * @param modelURL 模型文件的位置
 */
-(void)loadModelWithURL:(NSString *)modelURL;

@end

NS_ASSUME_NONNULL_END
