// 短网址服务

#include <stdio.h>
#include <stdlib.h>

#define MAX_COLUME 100

typedef struct URL
{
    char *code;      // 短码
    char *origin;    // 原址
    int id;          // 网址id
    int visit_times; // 有效次数
} URL;

typedef struct Manager
{
    int capacity;         // 网址数量
    URL save[MAX_COLUME]; // 存储数组
} Manager;

enum Menu
{
    生成短网址 = 1,
    访问短网址,
    查看网址,
    删除网址,
    查询网址,
    退出服务
};

int main(int argc, char const *argv[])
{
    int option; // 服务器选项
    do
    {
        printf("欢迎使用短网址服务！\n");
        printf("=====================\n");
        printf("1.生成短网址\n");
        printf("2.访问短网址\n");
        printf("3.查看网址\n");
        printf("4.删除网址\n");
        printf("5.查询网址\n");
        printf("6.退出服务\n");

        printf("请输入数字选择您要进行的操作：");
        scanf("%d", &option);
        switch (option)
        {
        case 生成短网址:
            break;

        case 访问短网址:
            break;

        case 查看网址:
            break;

        case 删除网址:
            break;

        case 查询网址:
            break;

        case 退出服务:
            break;

        default:
            break;
        }
    } while (option != 6);
    return 0;
}
