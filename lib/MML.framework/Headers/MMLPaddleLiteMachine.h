//
//  MMLPaddleLiteMachine.h
//  MML
//
//  Created by Wang,Zhiyong on 2020/2/11.
//  Copyright © 2020 Baidu. All rights reserved.
//

#import <MML/MML.h>
#import "MMLBaseMachine.h"

NS_ASSUME_NONNULL_BEGIN
///machine
@class PaddleLiteOC;
@class PaddleLiteConfig;
///input
@class MMLShapedData;
///output
@class MMLData;

@interface MMLPaddleLiteMachine : MMLBaseMachine

/*
 * @brief Action = 初始化模型 模型操作工具Machine
 * @param - modelDir 模型文件路径
 * @param - key 解密key 自行移位
 * @param - keysize 解密key 长度
 * @param - error 错误容器 （ErrorDomain:MMLPaddleMachineInitErrorDomain ErrorCode:PMachineErrorCode）
 * @return instancetype
 */
- (instancetype)initWithModelDir:(NSString *)modelDir
                      decryptKey:(const unsigned char *)key
                         keySize:(const unsigned int)keysize
                       withError:(NSError**)error;

@end

NS_ASSUME_NONNULL_END
