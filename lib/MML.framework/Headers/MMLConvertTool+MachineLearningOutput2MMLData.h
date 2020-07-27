//
//  MMLConvertTool+MachineLearningOutput2MMLData.h
//  MML
//
//  Created by Wang,Zhiyong on 2019/11/27.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMLConvertTool.h"
NS_ASSUME_NONNULL_BEGIN

/**
 转换工具 BML >> MMLData

 @param outputData 输入的BML output数据
 @return 转换后的MMLData
*/
@interface MMLConvertTool(MachineLearningOutput2MMLData)

/**
 BML output -> MMLdata

 @param outputData 输入的BML output数据
 @return 转换后的MMLData
*/
+ (MMLData *)convertMachineLearningOutputToMMLOutput:(MMLOutputData *)outputData;

@end

NS_ASSUME_NONNULL_END
