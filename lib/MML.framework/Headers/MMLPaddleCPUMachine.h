//
//  MMLPaddleCPUMachine.h
//  MML+Plugin
//
//  Created by QingCan on 2019/11/14.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import "MMLMachineCommonHeader.h"
#import "MMLBaseMachine.h"
#if __has_include("PaddleMobileCPU.h")
@class PaddleMobileCPUConfig;
@class MMLPaddlePredicateOutputs;
@class MMLInputMatrix;
#endif
NS_ASSUME_NONNULL_BEGIN

/// Paddle CPU 的Machine
@interface MMLPaddleCPUMachine : MMLBaseMachine
#if TARGET_IPHONE_SIMULATOR
#elif defined(__i386__)
#else
#if __has_include("PaddleMobileCPU.h")
/*
 * @brief Action = 初始化模型 模型操作工具Machine
 * @param - modelURL 模型文件URL（模型文件本身）
 * @param - paramPath params文件URL
 * @param - config PaddleCPU预测引擎配置
 * @param - key 解密key 自行移位
 * @param - keysize 解密key 长度
 * @param - error 错误容器 （ErrorDomain:MMLPaddleMachineInitErrorDomain ErrorCode:PMachineErrorCode）
 * @return instancetype
 */
- (instancetype)initWithModelPath:(NSString *)modelPath
                        paramPath:(NSString *)paramPath
                           config:(PaddleMobileCPUConfig *)config
                       decryptKey:(const unsigned char *)key
                          keySize:(const unsigned int)keysize
                        withError:(NSError**)error;

/*
* @brief Action = 初始化模型 模型操作工具Machine
* @param - modelPointer modelPointer 解密model指针
* @param - paramPointer paramPointer 解密param指针
* @param - modelSize 模型内存大小
* @param - paramSize 参数内存大小
* @param - config PaddleCPU预测引擎配置
* @param - error 错误容器
* @return MMLPredicateOutputs* 预测结果容器
*/
- (instancetype)initWithModelPointer:(unsigned char *)modelPointer
                        paramPointer:(unsigned char *)paramPointer
                           modelSize:(size_t)modelSize
                           paramSize:(size_t)paramSize
                              config:(PaddleMobileCPUConfig *)config
                           withError:(NSError**)error;

/*
 * @brief Action = 预测API
 * @param - input input容器
 * @return MMLPredicateOutputs* 预测结果容器
 */
- (MMLPaddlePredicateOutputs *)predicateWithInputMatrix:(MMLInputMatrix *)input;

/*
 * @brief Action = 预测API
 * @param - input input容器
 * @param - error 错误容器 （ErrorDomain:MMLMachinPredicateErrorDomain ErrorCode:PPredicateErrorCode）
 * @return MMLPredicateOutputs* 预测结果容器
 */
- (MMLPaddlePredicateOutputs *)predicateWithInputMatrix:(MMLInputMatrix *)input error:(NSError **)error;

#pragma mark - destroy

/*
 * @brief Action = 清除machine内存,且释放GPUMachine
 * @return BOOL YES:成功 NO:失败
 */
- (BOOL)releaseMachine;

/*
* @brief Action = 清理Machine内存
*/
- (void)clearMachine;
#endif
#endif
@end
NS_ASSUME_NONNULL_END
