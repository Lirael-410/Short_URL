// generate.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "generate.h"

const char hexdecimal[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void init(Manager *m)
{
    m->capacity = 0;
    m->init_id = 200;

    // 将表中所有位置标记为空
    for (int i = 0; i < MAX_COLUME; i++)
    {
        m->save[i].create = EMPTY;
    }
}

// 哈希取模，其中key代表id
int hash_cal(unsigned int key)
{
    return key % HASH_MOD;
}

// 存储网址，key代表id
int hash_save(Manager *m, unsigned int key)
{
    int index = hash_cal(key);
    int startIndex = index;

    // 当索引位置不为空（不考虑插入相同元素的情况）
    while (m->save[index].create != EMPTY)
    {
        // 索引加1
        index = (index + 1) % MAX_COLUME;

        // 回到起点
        if (index == startIndex)
        {
            printf("存储表已满\n");
            return -1;
        }
    }

    // 保存当前索引并储存
    m->save[index].create = index;
    return index;
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
    code[CODE_LENGTH] = '\0'; // 加上结束标识符
}

int generate(Manager *m, char *original_code, unsigned int times)
{
    if (strlen(original_code) > MAX_LENGTH)
    {
        printf("原址过长，无法进行生成操作\n");
        return EMPTY;
    }

    if (m->capacity == 100)
    {
        printf("储存网址数量已满，无法增加新网址\n");
        return EXIT_FAILURE;
    }

    m->capacity++;
    // 创建索引
    int index = hash_save(m, m->init_id);

    id_to_code(m->init_id, m->save[index].code);
    m->save[index].id = (m->init_id)++;
    strcpy(m->save[index].original, original_code);
    m->save[index].visit_times = times;

    printf("已成功创建\n");
    return index;
}

void save_to_file(char *original_code, char *code, int visit_times, int id)
{
    FILE *url = fopen("url.txt", "a");
    if (!url)
        perror("无法打开文件\n");
    else
    {
        fprintf(url, "%s\t%s\t%d\t%d\n", original_code, code, id, visit_times);
        fclose(url);
    }
}
