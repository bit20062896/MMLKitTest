//
//  MMLDecryptTools.h
//  MML+Plugin
//
//  Created by QingCan on 2019/11/14.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 默认的解密库解密工具
@interface MMLDecryptTools : NSObject
/**
 解密模型
 
 @param model_file_str 原始model文件
 @param key 解密key
 @param keysize key大小
 @param decrypt_output_size 解析content 内存大小
 @return 解密后的内存content
 */
unsigned char *decrypt_model(const char *model_file_str, const unsigned char *key, unsigned int keysize, unsigned int *decrypt_output_size);

@end

NS_ASSUME_NONNULL_END
