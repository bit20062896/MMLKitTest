//
//  MMLBMLGLMRegressorMachine.h
//  MML
//
//  Created by QingCan on 2019/12/16.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <MML/MML.h>
#import "MMLBaseMachine.h"

NS_ASSUME_NONNULL_BEGIN

// 预测结果回调的block
typedef void (^MMLGBDTRegressorMachineResultBlock)(MMLGBDTMachinePredicateState state, NSString * __nullable predicateResult);

@class MMLOutputData;
@class MMLInputData;
@interface MMLBMLGLMRegressorMachine : MMLBaseMachine

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
 * @brief 预测函数
 *
 * @param inputData 输入数据
 * @param error 预测结果的error
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
