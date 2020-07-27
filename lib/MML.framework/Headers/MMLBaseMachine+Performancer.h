//
//  MMLBaseMachine+Performancer.h
//  MML
//
//  Created by QingCan on 2019/12/9.
//  Copyright © 2019 Baidu. All rights reserved.
//


#import "MMLBaseMachine.h"

NS_ASSUME_NONNULL_BEGIN

/// 性能数据
@interface MMLBaseMachine (Performancer)

/// 纯inferenceEngine的加载时间
@property (nonatomic, copy) NSString *loadTime;
/// 纯inferenceEngine的预测时间
@property (nonatomic, copy) NSString *predictTime;
/// 纯解密时间
@property (nonatomic, copy) NSString *decryptTime;
/// 读取paddle的metal资源时间
@property (nonatomic, copy) NSString *readMetalResourceTime;

@end

NS_ASSUME_NONNULL_END
