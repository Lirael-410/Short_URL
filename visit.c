// visit.c
// 访问模块
#include <stdio.h>
#include "main.h"
#include "find.h"
#include "generate.h"
#include "visit.h"
#include "delete.h"

void visit(Manager *m, char *code)
{
    int index = find(m, code);
    if (index == -1)
    {
        printf("未找到该短码\n");
        return;
    }

    // 如果该网址访问次数已归零，自动删除该网址
    if (m->save[index].visit_times == 0)
    {
        printf("该网址访问次数已清零，无法访问\n");
        del_code(m, code);
        return;
    }

    printf("已访问 ");
    printf("%s\n", m->save[index].original);
    m->save[index].visit_times--;
}