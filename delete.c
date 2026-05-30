// delete.c
// 删除模块
#include <stdio.h>
#include "main.h"
#include "generate.h"
#include "delete.h"
#include "find.h"

void del_code(Manager *m, char *code)
{
    // 查询是否保存过该网址
    int index = find(m, code);
    if (index == -1)
    {
        printf("没有保存过该网址\n");
        return;
    }

    // 清空网址信息
    m->save[index].code[0] = '\0';
    m->save[index].original[0] = '\0';
    m->save[index].id = 0;
    m->save[index].visit_times = 0;
    m->save[index].create = EMPTY;

    m->capacity--;
    printf("删除成功!\n");
}
