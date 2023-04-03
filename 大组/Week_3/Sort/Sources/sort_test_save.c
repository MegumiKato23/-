#include <stdio.h>
#include <stdlib.h>
// #define MAX_LINE 100000
int main()
{
    int num, len, limit;
    // int buf[MAX_LINE];

    FILE *fp = fopen("test.txt", "w+");
    if (fp == NULL)
    {
        printf("打开文件失败!\n");
        return 0; 
    }

    printf("请输入你要生成的随机数组的大小:\n");
    scanf("%d", &len);
    printf("请输入你要的最大数据为:\n");
    scanf("%d", &limit);
    for (int i = 0; i < len; i++)
    {
        num = rand() % (limit + 1);
        fprintf(fp, "%d\n", num);
        // buf[i] = num;
    }
    printf("生成成功!\n");
    fclose(fp);
    return 0;
}