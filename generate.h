// generate.h
#ifndef GENARATE_H
#define GENARATE_H

#include "main.h"

#define HASH_MOD 89 // 哈希算法取模值
#define EMPTY -1    // 哈希表空位置标记
#define MAX_VISIT_TIMES 50  // 可设置的最多访问次数

// 初始化管理
void init(Manager *m);
int hash_cal(unsigned int key);
int hash_save(Manager *m, unsigned int key);
void id_to_code(unsigned int id, char *code);
int generate(Manager *m, char *original_code, unsigned int times);

extern const char hexdecimal[]; // 62进制表

#endif  // GENERATE_H