#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "sort.c"

int main()
{
    int len, max, choice;
    int *temp; // 缓冲区
    int *a;
    char c;

    printf("使用前请先使用sort_test_save生成数据\n");
    printf("请问是否继续?: y/n\n");
    while (1)
    {
        scanf("%c", &c);
        if (c == 'n' || c == 'N')
        {
            exit(0);
        }
        else if (c == 'y' || c == 'Y')
        {
            break;
        }
        else
        {
            printf("请重新输入! y/n\n");
        }
    }
    FILE *fp = fopen("test.txt", "r+");
    if (fp == NULL)
    {
        printf("打开文件失败!\n");
        return 0;
    }
    printf("请输入你要读取的随机数组的大小:\n");
    scanf("%d", &len);
    a = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        fscanf(fp, "%d\n", &a[i]);
    }

    while (1)
    {
        Show();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            insertSort(a, len);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 2:
        {
            temp = (int *)malloc(sizeof(int) * len);
            MergeSort(a, 0, len - 1, temp);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 3:
        {
            QuickSort_Recursion(a, 0, len - 1);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 4:
        {
            QuickSort(a, len);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 5:
        {
            Partition(a, 0, len - 1);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 6:
        {
            RandQuickSort(a, 0, len - 1);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 7:
        {
            printf("请输入数据的最大值:\n");
            scanf("%d", &max);
            CountSort(a, len, max);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 8:
        {
            printf("请输入数据的最大值:\n");
            scanf("%d", &max);
            RadixCountSort(a, len, max);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 9:
        {
            printf("请确保使用的数据最大值为2!!!\n");
            printf("请问是否继续: y/n\n");
            while (1)
            {
                char ch;
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                    break;
                }
                else if (ch == 'n' || ch == 'N')
                {
                    exit(0);
                }
            }
            ColorSort(a, len);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 10:
        {
            int k;
            printf("请输入你要找的第几的数字:\n");
            scanf("%d", &k);
            GetNumber(a, 0, len - 1, k);
            break;
        }
        case 11:
        {
            BubbleSort(a, len);
            for (int i = 0; i < len; i++)
            {
                printf("%d\n", a[i]);
            }
            break;
        }
        case 12:
        {
            exit(0);
        }
        default:
            break;
        }
        fclose(fp);

        FILE *file = fopen("test.txt", "w+");
        if (file == NULL)
        {
            printf("打开文件失败!\n");
            return 0;
        }
        for (int i = 0; i < len; i++)
        {
            fprintf(fp, "%d\n", a[i]);
        }
    }
    return 0;
}