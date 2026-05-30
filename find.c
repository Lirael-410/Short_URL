// find.c
// 查找模块
#include <string.h>
#include "generate.h"
#include "main.h"
#include "find.h"

// int find_by_code(Manager *m, char *code)
// {
//     for (int i = 0; i < MAX_COLUME; i++)
//     {
//         // 找到则返回下标
//         if (strncmp(code, m->save[i].code, 6) == 0)
//             return i;
//     }
//     return -1;
// }

int is_repeated(Manager *m, char *original_code)
{
    for (int i = 0; i < MAX_COLUME; i++)
    {
        // 有相同的返回真值
        if (!strcmp(original_code, m->save[i].original))
        {
            return 1;
        }
    }
    return 0;
}

unsigned int code_to_id(char *code)
{
    unsigned int id = 0;
    int c;
    for (int i = 0; i < 6; i++)
    {
        // 上一位先乘以62
        id *= 62;
        if (code[i] >= '0' && code[i] <= '9')
        {
            c = code[i] - '0';
        }
        else if (code[i] >= 'a' && code[i] <= 'z')
        {
            c = code[i] - 'a' + 10;
        }
        else if (code[i] >= 'A' && code[i] <= 'Z')
        {
            c = code[i] - 'A' + 36;
        }
        id += c;
    }
    return id;
}

int find(Manager *m, char *code)
{
    unsigned int id = code_to_id(code);
    // 获得初始哈希计算出的下标
    int index = hash_cal(id);
    while (m->save[index].create != EMPTY)
    {
        if (!strncmp(code, m->save[index].code, 6))
        {
            return index;
        }
        index = (index + 1) % MAX_COLUME;
    }

    return -1;
}
