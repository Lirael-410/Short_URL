// main.h
#ifndef MAIN_H
#define MAIN_H

#define MAX_COLUME 100
#define MAX_LENGTH 2048 // 原址最大长度
#define CODE_LENGTH 6   // 短码长度

typedef struct URL
{
    char code[CODE_LENGTH + 1];      // 短码
    char original[MAX_LENGTH + 1];    // 原址
    int id;          // 网址id
    int visit_times; // 有效次数
} URL;

typedef struct Manager
{
    int capacity;         // 网址数量
    int init_id;          // 初始id，从200开始
    URL save[MAX_COLUME]; // 存储数组
} Manager;

// 初始化管理
void init(Manager *m);


#endif  // MAIN_H