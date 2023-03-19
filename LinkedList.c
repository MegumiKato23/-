#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

#define True 1

//初始化链表
Status InitList(LinkedList *L)
{
    LinkedList list;
    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
        printf("分配内存失败!\n");
        return ERROR;
    }
    list->next = NULL;
    *L = list;
    return SUCCESS;
}

//销毁链表
void DestroyList(LinkedList *L)
{
    LinkedList p;
    while(*L != NULL)
    {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
}

//在目标节点后加入新的节点
Status InsertList(LNode *p, LNode *q)
{
    if(p == NULL || q == NULL)
    {
        printf("无法进行操作\n");
        return ERROR;
    }
    if(p->next == NULL)
    {
        p->next = q;
        q->next = NULL;
        return SUCCESS;
    }
    else
    {
        q->next = p->next;
        p->next = q;
        return SUCCESS;
    }
}

/*
//删除指定节点后的第一个节点并将值赋给e
Status DeleteList(LNode *p, ElemType *e)
{
    if(p->next == NULL)
    {
        printf("无法进行操作\n");
        return ERROR;
    }
    LNode *q = p->next;
    *e = p->next->data;
    p->next = q->next;
    free(q);
    return SUCCESS;
}
*/

//删除指定节点后的第一个值为e节点
Status DeleteList(LNode *p, ElemType *e)
{
    if(p == NULL)
    {
        printf("无法进行操作\n");
        return ERROR;
    }
    LinkedList p1 = p->next;
    LinkedList p2 = p;
    while(p1->data != *e)
    {
        p2 = p1;
        p1 = p1->next;
        if(p1 == NULL)
        {
            printf("查询不到该数据\n");
            return ERROR;
        }
    }
    p2->next = p1->next;
    free(p1);
    return SUCCESS;
}

//遍历链表
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    if (L == NULL)
    {
        printf("未创建链表,请先创建链表!\n");
    }
    else if (L->next == NULL)
    {
        printf("请先添加结点!\n");
    }
    else
    {
        LinkedList p = L->next;
        printf("%d", p->data);
        p = p->next;
        while (p != NULL)
        {
            // printf("->%d",p->data);
            visit(p->data);
            p = p->next;
        }

        printf("\n");
    }
}

void visit(ElemType e)
{
    printf("->%d", e);
}

//查找链表元素
Status SearchList(LinkedList L, ElemType e)
{
    while(L != NULL)
    {
        if(L->data == e)
        {
            return SUCCESS;
        }
        L = L->next;
    }
    return ERROR;
}

//反转链表
Status ReverseList(LinkedList *L)
{
    if((*L)->next == NULL)
    {
        return ERROR;
    }
    LinkedList p1, p2, pNew;
    p1 = (*L)->next;
    p2 = p1->next;
    (*L)->next = NULL;
    p1->next = NULL;
    pNew = p1;
    while(p2 != NULL)
    {
        p1 = p2;
        p2 = p1->next;
        p1->next = pNew;
        pNew = p1;
    }
    (*L)->next = pNew;
    return SUCCESS;
}

//判断是否成环
Status IsLoopList(LinkedList L)
{
    LinkedList fast = L, slow = L;
    while(fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if((fast = fast->next->next) == NULL)
        {
            return ERROR;
        }
        if(fast == slow)
        {
            return SUCCESS;
        }
    }
    return ERROR;
}

//单链表奇偶调换
LNode *ReverseEvenList(LinkedList *L)
// {
//     LinkedList p1, p2, p;
//     p1 = (*L);
//     p2 = (*L)->next;
//     (*L) = p2;
//     p1->next = p2->next;
//     p2->next = p1;
//     p = p1;
//     while(p1->next != NULL)
//     {
//         p1 = p;
//         p2 = p1->next;
//         p1->next = p2->next;
//         p2->next = p1;
//         p = p1;
//     }
//     return *L;  
// }
{
    LinkedList oddNode, evenNode, p;//奇偶
    oddNode = (*L)->next;
    evenNode = (*L)->next->next;
    p = evenNode->next;
    (*L)->next = evenNode;
    while(oddNode != NULL || evenNode != NULL)
    {
        if(p == NULL || p->next == NULL)
        {
            evenNode->next = oddNode;
            oddNode->next = NULL;
            break;
        }
        evenNode->next = oddNode;
        evenNode = p->next;
        oddNode->next = p;
        p = evenNode->next;
    }
    return *L;
}

//寻找中间结点
LNode *FindMidNode(LinkedList *L)
{
    LinkedList fast = L, slow = L;
    while(fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL)
        {
            return slow;
        }
    }
}

//菜单函数
void Show()
{
    printf("**********单链表ADT**********\n");
    printf("请选择你要进行的操作:\n");
    printf("1.初始化链表\n");
    printf("2.插入结点\n");
    printf("3.查找结点\n");
    printf("4.反转链表\n");
    printf("5.销毁链表\n");
    printf("6.遍历链表\n");
    printf("7.判断链表是否成环\n");
    printf("8.调换奇偶项\n");
    printf("9.寻找链表中间项\n");
    printf("10.退出\n");
    printf("请输入数字1-10:\n");
}





int main()
{
    LinkedList head = NULL;
    ElemType choice, e;
    
    while(True)
    {
        Show();
        scanf("%d",&choice);
        switch (choice)
        {
            case 1://初始化链表
            {
                if(InitList(&head))
                {
                    printf("初始化链表成功!\n");
                }
                else
                {
                    printf("初始化链表失败!\n");
                }
                break;
            }
            case 2://插入结点
            {
                LinkedList p = head, q;
                q = (LinkedList)malloc(sizeof(LNode));
                printf("请输入目标节点:\n");
                scanf("%d",&e);
                while(p->data != e)
                {
                    p = p->next;
                }
                printf("请输入添加的数据:\n");
                scanf("%d",&e);
                q->data = e;
                if(InsertList(p, q))
                {
                    printf("插入成功!\n");
                }
                else
                {
                    printf("插入失败!\n");
                }
                break;
            }
            case 3://查找结点
            {
                printf("请输入你要查找的结点:\n");
                scanf("%d",&e);
                if(SearchList(head, e))
                {
                    printf("存在!\n");
                }
                else
                {
                    printf("不存在!\n");
                }
                break;
            }
            case 4://反转链表
            {
                if(head == NULL ||head->next == NULL)
                {
                    printf("链表结点过少\n");
                    printf("反转失败!\n");
                }
                if(ReverseList(&head))
                {
                    printf("反转成功!\n");
                }
                else
                {
                    printf("反转失败!\n");
                }
                break;
            }
            case 5://销毁链表
            {
                DestroyList(&head);
                printf("删除成功!\n");
                break;
            }
            case 6://遍历链表
            {
                TraverseList(head, (*visit));
                break;
            }
            case 7://判断链表是否成环
            {
                if(IsLoopList(head))
                {
                    printf("成环\n");
                }
                else
                {
                    printf("不成环\n");
                }
                break;
            }
            case 8://调换奇偶项
            {
                if(head == NULL || head->next ==NULL)
                {
                    printf("链表结点过少！调换失败\n");
                    break;
                }
                head = ReverseEvenList(&head);
                printf("调换成功!\n");
                break;
            }
            case 9://寻找链表中间项
            {
                LinkedList p;
                p = FindMidNode(&head);
                printf("%d\n",p->data);
                break;
            }
            case 10://退出
            {
                exit(427);
                break;
            }
            default:
            {
                printf("请重新输入:\n");
                break;
            }
        }
    }
}
