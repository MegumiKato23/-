#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

// #define True 1

// #include <stdio.h>
// #include <stdlib.h>
// #include "duLinkedList.h"

#define True 1

// 初始化链表
Status InitList_DuL(DuLinkedList *L)
{
    DuLinkedList list;
    list = (DuLinkedList)malloc(sizeof(DuLNode));
    if (list == NULL)
    {
        printf("分配内存失败!\n");
        return ERROR;
    }
    list->next = NULL;
    list->prior = NULL;
    *L = list;
    return SUCCESS;
}

// 销毁链表
void DestroyList_DuL(DuLinkedList *L)
{
    DuLinkedList p;
    while (*L != NULL)
    {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
}

// 在目标节点前加入新的节点
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    if (p == NULL || q == NULL)
    {
        printf("无法进行操作\n");
        return ERROR;
    }
    if (p->prior == NULL)
    {
        p->prior = q;
        q->prior = NULL;
        q->next = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->prior;
        p->prior = q;
        q->prior = temp;
        temp->next = q;
        q->next = p;
    }
    return SUCCESS;
}

// 在目标节点后加入新的节点
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
    if (p == NULL || q == NULL)
    {
        printf("无法进行操作\n");
        return ERROR;
    }
    if (p->next == NULL)
    {
        p->next = q;
        q->prior = p;
        q->next = NULL;
    }
    else
    {
        DuLinkedList temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
    }
    return SUCCESS;
}

// 删除指定节点后的第一个值为e节点
Status DeleteList_DuL(DuLNode *p, ElemType *e)

{
    if (p->next == NULL)
    {
        printf("删除失败!\n");
        return ERROR;
    }
    else
    {
        DuLinkedList p1 = p->next, p2 = p;
        while (p1->data != *e)
        {
            p2 = p1;
            p1 = p1->next;
            if (p1 == NULL)
            {
                printf("查询不到该数据!\n");
                return ERROR;
            }
        }
        if (p1->next != NULL)
        {
            p2->next = p1->next;
            p1->next->prior = p2;
        }
        else
        {
            p2->next = NULL;
        }
        free(p1);
        return SUCCESS;
    }
}

// 遍历链表
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
    while (L->prior != NULL)
    {
        L = L->prior;
    }
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
        DuLinkedList p = L->next;
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

// 菜单函数
void show()
{
    printf("**********双链表ADT**********\n");
    printf("请选择你要进行的操作:\n");
    printf("1.初始化链表\n");
    printf("2.在指定的结点前插入结点\n");
    printf("3.在指定的结点后插入结点\n");
    printf("4.删除指定结点后第一个目标结点\n");
    printf("5.销毁链表\n");
    printf("6.遍历链表\n");
    printf("7.添加节点\n");
    printf("8.退出\n");
    printf("请输入数字1-8:\n");
}

// 判断输入数字是否符合标准
ElemType judge_Enter()
{
    char word[20];
    ElemType num;
    while (True)
    {
        scanf("%s", word);
        if (word[1] == '\0' && word[0] >= '1' && word[0] <= '8')
        {
            num = word[0] - '0';
            return num;
        }
        printf("输入有误,请重新输入:\n");
    }
}

// 添加结点
DuLinkedList add(DuLinkedList L, ElemType e)
{
    DuLinkedList p, q = L;
    p = (DuLinkedList)malloc(sizeof(DuLNode));
    p->data = e;
    p->next = NULL;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    return L;
}

int main()
{
    DuLinkedList head = NULL;

    while (True)
    {
        show();
        ElemType choice = judge_Enter();
        switch (choice)
        {
        case 1: // 初始化链表
        {
            if (InitList_DuL(&head))
            {
                printf("初始化链表成功!\n");
            }
            else
            {
                printf("初始化链表失败!\n");
            }
            break;
        }
        case 2: // 在指定的结点前插入结点
        {
            DuLinkedList p = head, q;
            ElemType e, flag = 1;
            q = (DuLinkedList)malloc(sizeof(DuLNode));
            q->next = NULL;
            printf("请输入目标结点的数值:\n");
            scanf("%d", &e);
            while (p->data != e)
            {
                if (p == NULL)
                {
                    flag = 0;
                    printf("无法查询到该结点\n");
                    break;
                }
                p = p->next;
            }
            if (flag)
            {
                printf("请输入要插入的结点值:\n");
                scanf("%d", &e);
                q->data = e;
                if (InsertBeforeList_DuL(p, q))
                {
                    printf("插入成功!\n");
                }
                else
                {
                    printf("插入失败!\n");
                }
            }
            break;
        }
        case 3: // 在指定的结点后插入结点
        {
            DuLinkedList p = head->next, q;
            ElemType e, flag = 1;
            q = (DuLinkedList)malloc(sizeof(DuLNode));
            q->next = NULL;
            printf("请输入目标结点的数值:\n");
            scanf("%d", &e);
            while (p->data != e)
            {
                if (p == NULL)
                {
                    flag = 0;
                    printf("无法查询到该结点\n");
                    break;
                }
                p = p->next;
            }
            if (flag)
            {
                printf("请输入要插入的结点值:\n");
                scanf("%d", &e);
                q->data = e;
                if (InsertAfterList_DuL(p, q))
                {
                    printf("插入成功!\n");
                }
                else
                {
                    printf("插入失败!\n");
                }
            }
            break;
        }
        case 4: // 删除指定结点后第一个目标结点
        {
            DuLinkedList p = head;
            ElemType e, flag = 1;
            printf("请输入指定结点的数值:\n");
            scanf("%d", &e);
            while (p->data != e)
            {
                if (p == NULL)
                {
                    flag = 0;
                    printf("无法查询到该结点\n");
                    break;
                }
                p = p->next;
            }
            if (flag)
            {
                printf("请输入要删除的目标结点:\n");
                scanf("%d", &e);
                if (DeleteList_DuL(p, &e))
                {
                    printf("删除成功!\n");
                }
                else
                {
                    printf("删除失败!\n");
                }
            }
            break;
        }
        case 5: // 销毁链表
        {
            DestroyList_DuL(&head);
            break;
        }
        case 6:// 遍历链表
        {
            TraverseList_DuL(head, (*visit));
            break;
        }
        case 7:// 增加结点
        {
            ElemType e;
            printf("请输入数值:\n");
            scanf("%d", &e);
            head = add(head, e);
            printf("添加成功!\n");
            break;
        }
        case 8:
        {
            DestroyList_DuL(&head);
            exit(427);
            break;
        }
        }
    }
}
