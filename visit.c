// visit.c
// 访问模块
#include "visit.h"

void visit(Manager *m, char *code)
{
    int index = find_by_code(m, code);
    if (index == -1)
    {
        printf("未找到该短码\n");
        return;
    }

    if (m->save[index].visit_times == 0)
    {
        printf("该网址访问次数已清零，无法访问\n");
        return;
    }

    printf("已访问 ");
    printf("%s\n", m->save[index].original);
    m->save[index].visit_times--;
}