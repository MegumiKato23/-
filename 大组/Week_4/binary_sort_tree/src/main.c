#include "binary_sort_tree.h"
#include "binary_sort_tree.c"

int main()
{
    int choice, data;
    BinarySortTreePtr bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    while (true)
    {
        Show();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            if (BST_init(&bst))
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
            printf("请输入你要插入的数据:\n");
            scanf("%d", &data);
            if (BST_insert(bst, data))
            {
                printf("插入成功!\n");
            }
            else
            {
                printf("插入失败!\n");
            }
            break;
        }
        case 3:
        {
            printf("请输入你要删除的节点:\n");
            scanf("%d", &data);
            if (BST_delete(bst, data))
            {
                printf("删除成功!\n");
            }
            else
            {
                printf("删除失败!\n");
            }
            break;
        }
        case 4:
        {
            printf("请输入你要查找的节点:\n");
            scanf("%d", &data);
            if (BST_search(bst, data))
            {
                printf("查找成功!\n");
            }
            break;
        }
        case 5:
        {
            BST_preorderI(bst, visit);
            printf("\n");
            break;
        }
        case 6:
        {
            BST_preorderR(bst->root, visit);
            printf("\n");
            break;
        }
        case 7:
        {
            BST_inorderI(bst, visit);
            printf("\n");
            break;
        }
        case 8:
        {
            BST_inorderR(bst->root, visit);
            printf("\n");
            break;
        }
        case 9:
        {
            BST_postorderI(bst, visit);
            printf("\n");
            break;
        }
        case 10:
        {
            BST_postorderR(bst->root, visit);
            printf("\n");
            break;
        }
        case 11:
        {
            BST_levelOrder(bst, visit);
            printf("\n");
            break;
        }
        case 12:
        {
            BST_insert(bst, 6);
            BST_insert(bst, 3);
            BST_insert(bst, 8);
            BST_insert(bst, 2);
            BST_insert(bst, 4);
            BST_insert(bst, 7);
            BST_insert(bst, 9);
            BST_insert(bst, 1);
            printf("插入成功!\n");
            break;
        }
        case 13:
        {
            exit(0);
        }
        default:
        {
            printf("请重新输入数字!\n");
            break;
        }
        }
    }
}
