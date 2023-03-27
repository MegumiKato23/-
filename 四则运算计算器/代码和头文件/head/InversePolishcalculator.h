#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef struct StackNodeChar
{
    char data;                  // 存数据
    struct StackNodeChar *next; // 存下一个结点的地址
} StackNodeChar, *LinkStackPtrChar;

typedef struct LinkStackChar
{
    LinkStackPtrChar top; // 栈顶指针
    int count;            // 栈中元素个数
} LinkStackChar;

typedef struct StackNodeInt
{
    int data;
    struct StackNodeInt *next;
} StackNodeInt, *LinkStackPtrInt;

typedef struct LinkStackInt
{
    LinkStackPtrInt top;
    int count;
} LinkStackInt;

// 链栈字符型
Status initLStackChar(LinkStackChar *s);                // 初始化栈
Status isEmptyLStackChar(LinkStackChar *s);             // 判断栈是否为空
Status pushLStackChar(LinkStackChar *s, char data);     // 入栈
Status popLStackChar(LinkStackChar *s, char *data);     // 出栈
// 链栈整型
Status initLStackInt(LinkStackInt *s);                 // 初始化栈
Status isEmptyLStackInt(LinkStackInt *s);              // 判断栈是否为空
Status pushLStackInt(LinkStackInt *s, int data);       // 入栈
Status popLStackInt(LinkStackInt *s, int *data);       // 出栈

#endif
