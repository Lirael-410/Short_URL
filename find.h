#ifndef FIND_H
#define FIND_H

#include <string.h>
#include "generate.h"
#include "main.h"

// 根据短码进行查找并返回下标，用于访问模块
// int find_by_code(Manager *m, char *code);
// 查询是否存入相同网址，用于生成模块
int is_repeated(Manager *m, char *original_code);
// 查找成功返回下标，不成功返回-1
int find(Manager *m, char *code);

#endif