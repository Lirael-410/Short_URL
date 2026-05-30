// 短网址服务

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "generate.h"
#include "find.h"
#include "visit.h"

int main(int argc, char const *argv[])
{
    int option; // 服务器选项
    Manager m;
    init(&m);
    char original_code[MAX_LENGTH + 1]; // 原址
    char code[CODE_LENGTH + 1];         // 短码
    unsigned int visit_times = 0;       // 访问（解析）次数，初始化为0
    do
    {
        printf("欢迎使用短网址服务！\n");
        printf("=====================\n");
        printf("1.生成短网址\n");
        printf("2.访问短网址\n");
        printf("3.查询网址\n");
        printf("4.删除网址\n");
        printf("5.退出服务\n");

        printf("请输入数字选择您要进行的操作：");
        scanf("%d", &option);
        switch (option)
        {
        case 生成短网址:
            printf("请输入原址：");
            scanf("%s", original_code);

            while (1)
            {
                printf("设置访问次数(不超过50)：");
                scanf("%u", &visit_times);
                if (visit_times > 50)
                    printf("设置的访问次数过大，请重新操作\n");
                else
                    break;
            }
            // 获得当前网址的索引
            int index = generate(&m, original_code, visit_times);
            // 将创建成功的网址保存进文件
            save_to_file(original_code, code, visit_times, m.save[index].id);
            printf("%s\n", m.save[index].code);
            break;

        case 访问短网址:
            printf("请输入网址短码：");
            scanf("%s", code);
            visit(&m, code);
            break;

        case 查询网址:
            
            break;

        case 删除网址:
            break;

        case 退出服务:
            break;

        default:
            printf("输入错误\n");
        }
    } while (option != 5);
    return 0;
}
