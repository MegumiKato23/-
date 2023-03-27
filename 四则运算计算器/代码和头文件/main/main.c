#include "InversePolishcalculator.h"
#include "InversePolishcalculator.c"

int main()
{
    LinkStackChar s1;
    LinkStackInt s2;
    char vect[50]; // 存放后缀表达式
    char num[20];  // 存放数字
    char c, e;
    int n = 0; // 用于数组

    // 初始化两个栈
    if (!initLStackChar(&s1))
    {
        printf("初始化失败!\n");
        exit(-1);
    }
    if (!initLStackInt(&s2))
    {
        printf("初始化失败!\n");
        exit(-1);
    }

    // 将中缀表达式转化为后缀表达式
    printf("请输入算数表达式,以'='作为结束标志(只能进行整数运算):\n");
    // scanf("%c", &c);
    c = getchar();
    printf("转化后的后缀表达式为:\n");
    while (c != '=')
    {
        while (c >= '0' && c <= '9')
        {
            vect[n++] = c;
            // vect[n++] = ' ';
            vect[n] = '\0';
            printf("%c", c);
            // scanf("%c", &c);
            c = getchar();
            if (c <= '0' || c >= '9')
            {
                printf(" ");
                vect[n++] = ' ';
                vect[n] = '\0';
            }
        }
        if (c == '(')
        {
            pushLStackChar(&s1, c);
        }
        else if (c == ')')
        {
            popLStackChar(&s1, &e);
            while (e != '(')
            {
                printf("%c ", e);
                vect[n++] = e;
                vect[n++] = ' ';
                vect[n] = '\0';
                popLStackChar(&s1, &e);
            }
        }
        else if (c == '+' || c == '-')
        {
            if (isEmptyLStackChar(&s1))
            {
                pushLStackChar(&s1, c);
            }
            else
            {
                do
                {
                    popLStackChar(&s1, &e);
                    if (e == '(')
                    {
                        pushLStackChar(&s1, e);
                    }
                    else
                    {
                        vect[n++] = e;
                        vect[n++] = ' ';
                        vect[n] = '\0';
                        printf("%c ", e);
                    }
                } while (!isEmptyLStackChar(&s1) && e != '(');
                pushLStackChar(&s1, c);
            }
        }
        else if (c == '*' || c == '/')
        {
            pushLStackChar(&s1, c);
        }
        else if (c == '=')
        {
            break;
        }
        else
        {
            printf("输入表达式错误,请重新输入!\n");
            exit(-1);
        }
        // scanf("%c", &c);
        c = getchar();
    }

    // 最后栈不为空，全部弹出
    while (!isEmptyLStackChar(&s1))
    {
        popLStackChar(&s1, &e);
        printf("%c ", e);
        vect[n++] = e;
        vect[n++] = ' ';
        vect[n] = '\0';
    }
    vect[n++] = '=';
    vect[n++] = ' ';
    vect[n] = '\0';
    printf("= ");
    // printf("\n%s\n", vect);

    // // 后缀表达式的运算
    int m = 0, k = 0; // 用于计算数组
    int a, b;         // 用于做运算
    e = vect[m++];
    // printf("%c", e);
    while (e != '=')
    {
        while (e >= '0' && e <= '9')
        {
            num[k++] = e;
            num[k] = '\0';
            e = vect[m++];
            if (e == ' ')
            {
                a = atoi(num);
                pushLStackInt(&s2, a);
                k = 0;
                break;
            }
        }
        switch (e)
        {
        case '+':
        {
            popLStackInt(&s2, &a);
            popLStackInt(&s2, &b);
            pushLStackInt(&s2, a + b);
            break;
        }
        case '-':
        {
            popLStackInt(&s2, &a);
            popLStackInt(&s2, &b);
            pushLStackInt(&s2, b - a);
            break;
        }
        case '*':
        {
            popLStackInt(&s2, &a);
            popLStackInt(&s2, &b);
            pushLStackInt(&s2, a * b);
            break;
        }
        case '/':
        {
            popLStackInt(&s2, &a);
            popLStackInt(&s2, &b);
            if (a == 0 || b == 0)
            {
                printf("除数不能为0!\n");
                exit(-1);
            }
            pushLStackInt(&s2, b / a);
            break;
        }
        case ' ':
        {
            break;
        }
        }
        e = vect[m++];
    }
    popLStackInt(&s2, &a);
    printf("%d\n", a);
    return 0;
}