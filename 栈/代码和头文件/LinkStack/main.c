#include "LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>
#include <stdlib.h>

#define True 1

int main()
{
    int choice;
    ElemType data, temp;
    LinkStack s;
    while (True)
    {
        show();
        choice = judge_num();
        switch (choice)
        {
        case 1:
        {
            if (initLStack(&s))
            {
                printf("初始化成功!\n");
            }
            else
            {
                printf("初始化失败!\n");
            }
            break;
        }
        case 2:
        {
            printf("请输入你要加入的数据:\n");
            scanf("%d", &data);
            if (pushLStack(&s, data))
            {
                printf("入栈成功!\n");
            }
            else
            {
                printf("入栈失败!\n");
            }
            break;
        }
        case 3:
        {
            if (popLStack(&s, &data))
            {
                printf("出栈成功!\n");
            }
            else
            {
                printf("出栈失败!\n");
            }
            break;
        }
        case 4:
        {
            if (isEmptyLStack(&s))
            {
                printf("栈为空!\n");
            }
            else
            {
                printf("栈不为空!\n");
            }
            break;
        }
        case 5:
        {
            if (clearLStack(&s))
            {
                printf("清空成功!\n");
            }
            else
            {
                printf("清空失败!\n");
            }
            break;
        }
        case 6:
        {
            if (destroyLStack(&s))
            {
                printf("销毁成功!\n");
            }
            else
            {
                printf("销毁失败!\n");
            }
            break;
        }
        case 7:
        {
            int length = 0;
            LStackLength(&s, &length);
            break;
        }
        case 8:
        {
            int e = 0;
            if (getTopLStack(&s, &e))
            {
                printf("栈顶元素为\t%d\n", e);
            }
            else
            {
                printf("不存在栈顶元素!\n");
            }
            break;
        }
        case 9:
        {
            exit(427);
        }
        default:
        {
            printf("请重新输入1-9的整数!\n");
            break;
        }
        }
    }
}