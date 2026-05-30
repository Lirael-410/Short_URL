// find.c
// 查找模块
#include "find.h"

int find_by_code(Manager *m, char *code)
{
    for (int i = 0; i < MAX_COLUME; i++)
    {
        // 找到则返回下标
        if (strncmp(code, m->save[i].code, 6) == 0)
            return i;
    }
    return -1;
}
