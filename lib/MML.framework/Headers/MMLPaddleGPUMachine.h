//
//  MMLPaddleGPUMachine.h
//  MML+Plugin
//
//  Created by QingCan on 2019/11/14.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLBaseMachine.h"
//#import "PaddleMobileGPU.h"
#import <MMLSDK/PaddleMobileGPU.h>


@class MMLInputMatrix;

NS_ASSUME_NONNULL_BEGIN

typedef void (^MMLPaddleGPUPredicatOutputsCallback)(PaddleMobileGPUResult *__nullable gpuPredicateOutputs, NSError *__nullable error);
typedef void (^MMLPaddleGPUPredicatOutputArrayCallback)(NSArray<PaddleMobileGPUResult *> *__nullable gpuPredicateOutputs, NSError *__nullable error);

/// Paddle GPU 的Machine
@interface MMLPaddleGPUMachine : MMLBaseMachine

/*
 * @brief Action = 初始化模型 模型操作工具Machine
 * @param - modelURL 模型文件URL（模型文件本身）
 * @param - paramPath params文件URL
 * @param - key 解密key 自行移位
 * @param - keysize 解密key 长度
 * @param - netType 网络类型
 * @param - config 原始ModelConfig
 * @param - error 错误容器 （ErrorDomain:MMLPaddleMachineInitErrorDomain ErrorCode:PMachineErrorCode）
 * @return instancetype
 */
- (instancetype __nullable)initWithModelPath:(NSString *)modelPath
                                   paramPath:(NSString *)paramPath
                                  decryptKey:(const unsigned char *)key
                                     keySize:(const unsigned int)keysize
                                     netType:(NetType)netType
                                 modelConfig:(ModelConfig *)config
                                   withError:(NSError **)error;


/**
 初始化模型

 @param modelConfig modelconfig配置
 @param netType 网络类型
 @param error 错误容器
 @return instancetype
 */
- (instancetype __nullable)initWithModelConfig:(ModelConfig *)modelConfig
                                       netType:(NetType)netType
                                     withError:(NSError**)error;

/**
 预测接口
 
 @param input 输入容器
 @param callback 结果容器
 */
- (void)predictWithInputMatrix:(MMLInputMatrix *)input
               completionBlock:(MMLPaddleGPUPredicatOutputsCallback)callback;


/**
 清除machine内存
 */
- (void)clearMachine;

/**
 清除machine内存,且释放GPUMachine
 */
- (void)releasePaddleMobileGPU;

/**
 重新load machine
 */
- (void)reloadMachineWithError:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
