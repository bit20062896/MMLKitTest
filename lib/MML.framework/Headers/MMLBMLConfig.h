//
//  MMLBMLConfig.h
//  MML
//
//  Created by QingCan on 2019/11/20.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLInferenceEngineConfigProtocol.h"
#import <MMLSDK/MMLSDK.h>
NS_ASSUME_NONNULL_BEGIN
/// BML Machine的配置
@interface MMLBMLConfig : NSObject <MMLInferenceEngineConfigProtocol>
/// 是否切换使用CoreML类型的Machine
@property (nonatomic, assign) BOOL switchToCoreMLMachine;
/// 输入容器数据类型，machineType == GBDTRegression 时需要配置此参数
@property (nonatomic, assign) MMLGBDTInputDataType inputDataType;
/// 模型内存指针
@property (nonatomic, assign) unsigned char * modelPointer;
/// 模型内存大小
@property (nonatomic, assign) size_t modelSize;
@end

NS_ASSUME_NONNULL_END
