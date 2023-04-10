//
// Created by eke_l on 2021/4/21.
//

#include <stdio.h>

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define MAX_SIZE 100
#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

// 二叉树的结构
typedef struct Node
{
    ElemType value; // 存储数据
    struct Node *left, *right; // 左结点 右结点
} Node, *NodePtr;

// 二叉排序树的根节点
typedef struct BinarySortTree
{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

typedef struct Stack
{
    NodePtr data[MAX_SIZE]; // 栈
    ElemType top; // 栈顶指针
} Stack;

// 队列
typedef struct Queue 
{
    NodePtr data[MAX_SIZE]; // 存储数据的数组
    ElemType head; // 队首索引
    ElemType tail; // 队尾索引
} Queue;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr *bst);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr bst, ElemType data);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr bst, ElemType data);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr bst, ElemType data);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr node, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr node, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr node, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr));

// 遍历
void visit(NodePtr node);

// 入栈
void push(Stack *stack, NodePtr node);

// 出栈
NodePtr pop(Stack *stack);

// 获取栈顶元素
NodePtr stackTop(Stack *stack);

// 判空
Status isEmpty(Queue queue);

// 判满
Status isFull(Queue queue);

// 入队
Status enqueue(Queue *queue, NodePtr data);

// 出队
NodePtr dequeue(Queue *queue);

void Show();

#endif // BINARYSORTTREE_BINARY_SORT_TREE_H
