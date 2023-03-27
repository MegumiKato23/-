#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 链栈

// 初始化栈
Status initLStack(LinkStack *s)
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

// 判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
    if (s->top == NULL)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

// 得到栈顶元素
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (s->top == NULL)
    {
        printf("栈为空!\n");
        return ERROR;
    }
    else
    {
        *e = s->top->data;
        return SUCCESS;
    }
}

// 清空栈
Status clearLStack(LinkStack *s)
{
    if (s->top == NULL)
    {
        printf("栈为空!\n");
        return ERROR;
    }
    else
    {
        s->top = NULL;
        return SUCCESS;
    }
}

// 销毁栈
Status destroyLStack(LinkStack *s)
{
    while (!isEmptyLStack(s))
    {
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
        s->count--;
    }
    return SUCCESS;
}

// 检测栈长度
Status LStackLength(LinkStack *s, int *length)
{
    if (s->top == NULL)
    {
        printf("栈为空!\n");
        return ERROR;
    }
    else
    {
        length = &s->count;
        printf("栈的长度为\t%d\n", *length);
        return SUCCESS;
    }
}

// 入栈
Status pushLStack(LinkStack *s, ElemType data)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if (s == NULL)
    {
        printf("分配内存失败!\n");
        return ERROR;
    }
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
    return SUCCESS;
}

// 出栈
Status popLStack(LinkStack *s, ElemType *data)
{
    if (s->top == NULL)
    {
        printf("栈为空!\n");
        return ERROR;
    }
    LinkStackPtr p;
    *data = s->top->data;
    p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}

void show()
{
    printf("**********链栈**********\n");
    printf("请选择你要进行的操作:\n");
    printf("1.初始化栈\n");
    printf("2.入栈\n");
    printf("3.出栈\n");
    printf("4.判断栈是否为空\n");
    printf("5.清空栈\n");
    printf("6.销毁栈\n");
    printf("7.检测栈的长度\n");
    printf("8.获得栈顶元素\n");
    printf("9.退出\n");
    printf("请输入数字1-9进行操作:\n");
}

int judge_num()
{
    char word[20];
    int len, num = 0;
    int flag = 1;
    while (flag)
    {
        scanf("%s", word);
        len = strlen(word);
        for (int i = 0; i < len; i++)
        {
            if (word[i] < '0' || word[i] > '9')
            {
                printf("请输入整数!\n");
                break;
            }
            else
            {
                if (i == len - 1)
                {
                    flag = 0;
                }
            }
        }
    }
    int m = len - 1, arg = 1;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arg *= 10;
        }
        num += (word[i] - '0') * arg;
        arg = 1;
        m--;
    }
    return num;
}
