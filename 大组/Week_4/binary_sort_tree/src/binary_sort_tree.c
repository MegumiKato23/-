#include "binary_sort_tree.h"
#include <stdlib.h>

// 二叉排序树的初始化
Status BST_init(BinarySortTreePtr *bst)
{
    (*bst) = (BinarySortTree *)malloc(sizeof(BinarySortTree));
    if ((*bst) == NULL)
    {
        return false;
    }
    (*bst)->root = NULL;
    return succeed;
}

// 插入节点
Status BST_insert(BinarySortTreePtr bst, ElemType data)
{
    NodePtr node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("内存分配失败!\n");
        return false;
    }
    NodePtr current = bst->root; // 记录目前的节点
    NodePtr parent = NULL; // 记录父节点

    while (current != NULL && current->value != data)
    {
        parent = current;
        if (data < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current != NULL && current->value == data)
    {
        printf("插入失败!存在相同数据!\n");
        return false;
    }

    node->value = data;
    node->left = NULL;
    node->right = NULL;

    if (parent == NULL)
    {
        bst->root = node;
    }
    else if (data < parent->value)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
    return succeed;
}

//  删除节点
Status BST_delete(BinarySortTreePtr bst, ElemType data)
{
    if (bst->root == NULL || bst == NULL) // 如果不存在
    {
        return false;
    }

    NodePtr current = bst->root; // 记录现在的节点
    NodePtr parent = NULL;       // 记录父节点

    while (current != NULL && current->value != data) // 寻找要删除的节点current
    {
        parent = current;
        if (data < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == NULL)
    {
        return false;
    }

    NodePtr child = NULL; // 记录子节点

    if (current->left != NULL)
    {
        child = current->left;
    }
    else if (current->right != NULL)
    {
        child = current->right;
    }

    // 如果要删除的节点是根节点root
    if (parent == NULL)
    {
        bst->root = child;
    }
    else if (current == parent->left)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    free(current);
    return succeed;
}

// 查找节点
Status BST_search(BinarySortTreePtr bst, ElemType data)
{
    NodePtr root = bst->root;
    while (root != NULL && root->value != data)
    {
        if (data < root->value)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (root == NULL)
    {
        printf("查找失败，不存在该数据!\n");
        return false;
    }
    else
    {
        return succeed;
    }
}

void visit(NodePtr node)
{
    printf("%d ", node->value);
}


// 入栈操作
void push(Stack *stack, NodePtr node)
{
    stack->top++;
    stack->data[stack->top] = node;
}

// 出栈操作
NodePtr pop(Stack *stack)
{
    NodePtr node = stack->data[stack->top];
    stack->top--;
    return node;
}

// 获取栈顶元素
NodePtr stackTop(Stack *stack)
{
    return stack->data[stack->top];
}

// 先序遍历非递归
Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
    Stack stack = {{NULL}, -1};

    if (bst->root == NULL)
    {
        return false;
    }
    NodePtr node = bst->root;
    push(&stack, node);

    // 在树不为空或者栈不为空时执行循环
    while (stack.top >= 0)
    {
        node = pop(&stack); // 弹出栈顶      
        while (node != NULL)
        {
            visit(node); // 访问栈顶
            if (node->right != NULL)
            {
                push(&stack, node->right);
            }
            node = node->left;
        }
    }

    return succeed;
}

// 先序遍历递归
Status BST_preorderR(NodePtr node, void (*visit)(NodePtr))
{
    // 判断是否为空
    if (node != NULL)
    {
        visit(node);
        BST_preorderR(node->left, visit);
        BST_preorderR(node->right, visit);
    }
    
    return succeed;
}

// 中序遍历非递归
Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
    Stack stack = {{NULL}, -1}; // 初始化一个空栈

    if (bst->root == NULL)
    {
        return false;
    }

    NodePtr node = bst->root;

    // 在树不为空或者栈不为空时执行循环
    while (node != NULL || (stack.top >= 0))
    {
        // 把左子树全部入栈
        while (node != NULL)
        {
            push(&stack, node);
            node = node->left;
        }
        node = pop(&stack); // 弹出栈顶
        visit(node);        // 访问栈顶
        node = node->right; // 继续处理右子树
    }

    return succeed;
}

// 中序遍历递归
Status BST_inorderR(NodePtr node, void (*visit)(NodePtr))
{
    // 判断是否为空
    if (node != NULL)
    {
        BST_inorderR(node->left, visit);
        visit(node);
        BST_inorderR(node->right, visit);
    }
    
    return succeed;
}

// 后序遍历非递归
Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
    Stack stack = {{NULL}, -1}; // 初始化一个空栈

    if (bst->root == NULL)
    {
        return false;
    }

    NodePtr node = bst->root;
    NodePtr top, p = NULL;

    // 在树不为空或者栈不为空时执行循环
    while (node != NULL || (stack.top >= 0))
    {
        while (node != NULL)
        {
            push(&stack, node);
            node = node->left;
        }
        top = stackTop(&stack);
        if (top->right == NULL || top->right == p)
        {
            visit(top);
            pop(&stack);
            p = top;
        }
        else
        {
            node = top->right;
        }
    }

    return succeed;
}

// 后序遍历递归
Status BST_postorderR(NodePtr node, void (*visit)(NodePtr))
{
    // 判断是否为空
    if (node != NULL)
    {
        BST_postorderR(node->left, visit);
        BST_postorderR(node->right, visit);
        visit(node);
    }
    
    return succeed;
}

Status isEmpty(Queue queue)
{
    return queue.head == queue.tail;
}

Status isFull(Queue queue)
{
    return queue.tail == MAX_SIZE;
}

// 初始化队列
void initQueue(Queue *queue) 
{
    queue->head = 0;
    queue->tail = 0;
    for (int i = 0; i < MAX_SIZE; i++) 
    {
        queue->data[i] = NULL;
    }
}

// 入队
Status enqueue(Queue *queue, NodePtr node)
{
    if (isFull(*queue))
    {
        return false;
    }
    queue->data[queue->tail++] = node;
    return succeed;
}

// 出队
NodePtr dequeue(Queue *queue)
{
    if (isEmpty(*queue))
    {
        return false;
    }
    NodePtr node = queue->data[queue->head++];
    return node;
}

// 层序遍历
Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr))
{
    if (bst->root == NULL)
    {
        return false;
    }

    Queue queue;
    initQueue(&queue);
    enqueue(&queue, bst->root);

    // 判断是否为空
    while (!isEmpty(queue))
    {
        NodePtr node = dequeue(&queue);
        visit(node);
        if (node->left != NULL)
        {
            enqueue(&queue, node->left);
        }
        if (node->right != NULL)
        {
            enqueue(&queue, node->right);
        }
    } 
    return succeed;
}

void Show()
{
    printf("*********二叉排序树ADT*********\n");
    printf("1.初始化二叉排序树\n");
    printf("2.插入节点\n");
    printf("3.删除节点\n");
    printf("4.寻找节点\n");
    printf("5.先序遍历非递归\n");
    printf("6.先序遍历递归\n");
    printf("7.中序遍历非递归\n");
    printf("8.中序遍历递归\n");
    printf("9.后序遍历非递归\n");
    printf("10.后序遍历递归\n");
    printf("11.层序遍历\n");
    printf("12.一键快速插入节点(方便测试)\n");
    printf("13.退出\n");
    printf("请输入1-13选择你要进行的操作\n");
}
