//
//  MMLMachineConfigProtocol.h
//  MML+Plugin
//
//  Created by QingCan on 2019/11/13.
//  Copyright © 2019 Baidu. All rights reserved.
//

#ifndef MMLMachineConfigProtocol_h
#define MMLMachineConfigProtocol_h
#import "MMLInferenceEngineConfigProtocol.h"
#import <MMLSDK/MMLInputData.h>
/// Machine的类型
typedef NS_ENUM (NSUInteger, MMLMachineType) {
    MMLGBDTClassify = 0,       // GBDT 分类
    MMLGBDTRegression,         // GBDT 回归
    MMLLogicRegression,        // 逻辑回归
    MMLLinearRegression,       // 线性回归
    MMLPaddleCPU,              // paddle CPU Machine
    MMLPaddleGPU,              // paddle GPU Machine
    MMLPaddleLite              // paddle GPU Machine
};

typedef enum {
    MMLAlreadyEncrypt = 0,     // 已经加密，需要解密
    MMLAlreadyDecrypt,         // 已经解密，不需要解密
    MMLInfEngineCrypt          // inf引擎加密，需要inf引擎解密
} MMLDecryptType;

/// 默认解密配置
typedef struct {
    MMLDecryptType decryptType; // 加解密类型
    unsigned int keySize;       // 解密Key大小
    unsigned char * key;        // 解密key内存指针
} MMLDecryptInfo;


/// MMLMachine的公共协议
@protocol MMLMachineConfigProtocol <NSObject>
/// Machine类型,参数必传，代表使用什么底层inference框架
@property (nonatomic, assign) MMLMachineType machineType;
/// 模型文件地址，通过已存在的Model地址加载Machine
@property (nonatomic, copy) NSString *modelPath;
/// 使用默认解密库时，自定义的解密key
@property (nonatomic, assign) MMLDecryptInfo decryptInfo;
/// inference引擎特殊的配置
@property (nonatomic, strong) id <MMLInferenceEngineConfigProtocol> engineConifg;
/// 可以设置自定义的logger
@property (nonatomic, copy) NSString *loggerClassName;

@end
#endif /* MMLModelConfigProtocol_h */
