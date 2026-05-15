// generate.c
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "generate.h"

const char hexdecimal[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void init(Manager *m)
{
    m->capacity = 0;
    m->init_id = 200;
}

void id_to_code(unsigned int id, char *code)
{
    // 临时数组，储存短码
    char temp[10];
    unsigned int num = id;
    int i = 0;

    // 计算短码
    while (num != 0)
    {
        temp[i] = hexdecimal[num % 62];
        i++;
        num /= 62;
    }

    // 短码不足6位补零
    for (int j = i; j < CODE_LENGTH; j++)
    {
        temp[j] = hexdecimal[0];
    }

    // 倒序输出给code[]
    for (int j = 0; j < CODE_LENGTH; j++)
    {
        code[j] = temp[CODE_LENGTH - j - 1];
    }
    code[CODE_LENGTH] = "\0";   // 加上结束标识符
}

void generate(Manager *m, char *original_code)
{
    if (strlen(original_code) > MAX_LENGTH)
    {
        printf("原址过长，无法进行生成操作\n");
        return;
    }

    m->capacity++;
}
