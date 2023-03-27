#include "InversePolishcalculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链栈字符型
// 初始化栈
Status initLStackChar(LinkStackChar *s)
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

// 判断栈是否为空
Status isEmptyLStackChar(LinkStackChar *s)
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

// 入栈
Status pushLStackChar(LinkStackChar *s, char data)
{
    LinkStackPtrChar p = (LinkStackPtrChar)malloc(sizeof(StackNodeChar));
    if (p == NULL)
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
Status popLStackChar(LinkStackChar *s, char *data)
{
    if (s->top == NULL)
    {
        printf("栈为空!\n");
        return ERROR;
    }
    LinkStackPtrChar p;
    p = s->top;
    *data = s->top->data;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}

// 链栈整型
// 初始化栈
Status initLStackInt(LinkStackInt *s)
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

// 判断栈是否为空
Status isEmptyLStackInt(LinkStackInt *s)
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

// 入栈
Status pushLStackInt(LinkStackInt *s, int data)
{
    LinkStackPtrInt p = (LinkStackPtrInt)malloc(sizeof(StackNodeInt));
    if (p == NULL)
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
Status popLStackInt(LinkStackInt *s, int *data)
{
    if (s->top == NULL)
    {
        printf("栈为空!\n");
        return ERROR;
    }
    LinkStackPtrInt p;
    p = s->top;
    *data = s->top->data;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}
