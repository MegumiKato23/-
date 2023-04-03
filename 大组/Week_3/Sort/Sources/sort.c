#include "sort.h"
#include "LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>

// 插入排序
void insertSort(int *a, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

// 归并排序（合并数组）
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
    int p1 = begin, p2 = mid + 1;
    int p = 0;

    while (p1 <= mid && p2 <= end)
    {
        if (a[p1] <= a[p2])
        {
            temp[p++] = a[p1++];
        }
        else
        {
            temp[p++] = a[p2++];
        }
    }
    while (p1 <= mid)
    {
        temp[p++] = a[p1++];
    }
    while (p2 <= end)
    {
        temp[p++] = a[p2++];
    }
    for (int i = 0; i < p; i++)
    {
        a[i + begin] = temp[i];
    }
}

// 归并排序
void MergeSort(int *a, int begin, int end, int *temp)
{
    if (begin >= end)
    {
        return;
    }
    int mid = (begin + end) / 2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);
    MergeArray(a, begin, mid, end, temp);
}

// 快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end)
{
    int pivot = a[begin];
    int left = begin, right = end;
    int index = begin;
    // while (left <= right)
    // {
    //     while (a[right] > pivot)
    //     {
    //         right--;
    //     }
    //     a[index] = a[right--];
    //     index = right;
    //     while (a[left] < pivot)
    //     {
    //         left++;
    //     }
    //     a[index] = a[left++];
    //     index = left;
    // }
    // a[index] = pivot;

    while (left <= right)
    {
        while (a[left] < pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            index = a[left];
            a[left] = a[right];
            a[right] = index;
            left++;
            right--;
        }
    }

    if (left < end)
    {
        QuickSort_Recursion(a, left, end);
    }
    if (begin < right)
    {
        QuickSort_Recursion(a, begin, right);
    }
}

// 快速排序（非递归版）
void QuickSort(int *a, int size)
{

    LinkStack s;
    initLStack(&s);
    pushLStack(&s, size - 1);
    pushLStack(&s, 0);

    while (!isEmptyLStack(&s))
    {
        int left;
        popLStack(&s, &left);
        int right;
        popLStack(&s, &right);

        int pivot = a[left];
        int begin = left, end = right;
        while (begin < end)
        {
            while (a[end] >= pivot && begin < end)
            {
                end--;
            }
            a[begin] = a[end];
            while (a[begin] <= pivot && begin < end)
            {
                begin++;
            }
            a[end] = a[begin];
        }
        a[begin] = pivot;
        int mid = begin;

        if (left < mid - 1)
        {
            pushLStack(&s, mid - 1);
            pushLStack(&s, left);
        }
        if (right > mid + 1)
        {
            pushLStack(&s, right);
            pushLStack(&s, mid + 1);
        }
    }
}

// 快速排序（枢轴存放）
int Partition(int *a, int begin, int end)
{
    int pivot = NumberOfThree(a, begin, end);
    int left = begin, right = end;
    int index = begin;

    while (left <= right)
    {
        while (a[left] < pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            index = a[left];
            a[left] = a[right];
            a[right] = index;
            left++;
            right--;
        }
    }

    if (left < end)
    {
        QuickSort_Recursion(a, left, end);
    }
    if (begin < right)
    {
        QuickSort_Recursion(a, begin, right);
    }
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 三数取中
int NumberOfThree(int *a, int begin, int end)
{
    int mid = (begin + end) / 2 + begin;

    if (a[end] < a[begin])
    {
        Swap(&a[end], &a[begin]);
    }
    if (a[end] < a[mid])
    {
        Swap(&a[end], &a[mid]);
    }
    a[mid] = a[mid] > a[begin] ? a[mid] : a[begin];
    return a[mid];
}

// 计数排序
void CountSort(int *a, int size, int max)
{
    int *count, *ans;
    count = (int *)malloc(sizeof(int) * (max + 1));
    ans = (int *)malloc(sizeof(int) * size);
    if (count == NULL || ans == NULL)
    {
        printf("分配内存失败!\n");
        return;
    }
    // 初始化
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    // 收集数据
    for (int i = 0; i < size; i++)
    {
        count[a[i]]++;
    }
    // 统计数组
    for (int i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        count[a[i]]--;
        ans[count[a[i]]] = a[i];
    }
    for (int i = 0; i < size; i++)
    {
        a[i] = ans[i];
    }
    free(count);
    free(ans);
}

// 基数计数排序
void RadixCountSort(int *a, int size, int max)
{
    int index, rad = 1;
    int *count, *ans;

    count = (int *)malloc(sizeof(int) * 10);
    ans = (int *)malloc(sizeof(int) * size);
    if (count == NULL || ans == NULL)
    {
        printf("内存分配失败!\n");
        return;
    }
    while (max / rad > 0)
    {
        // 初始化数组
        for (int i = 0; i < 10; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            index = a[i] / rad % 10;
            count[index]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = size - 1; i >= 0; i--)
        {
            index = a[i] / rad % 10;
            count[index]--;
            ans[count[index]] = a[i];
        }
        for (int i = 0; i < size; i++)
        {
            a[i] = ans[i];
        }
        rad *= 10;
    }
    free(count);
    free(ans);
}

// 颜色排序
void ColorSort(int *a, int size)
{
    int left = 0, right = size - 1;
    for (int i = 0; i <= right; i++)
    {
        if (a[i] == 0)
        {
            Swap(&a[i], &a[left++]);
        }
        else if (a[i] == 2)
        {
            Swap(&a[i--], &a[right--]);
        }
    }
}

// 在一个无序序列中找到第K大/小的数
void GetNumber(int *a, int begin, int end, int k)
{
    int pivot = a[begin];
    int left = begin, right = end;
    int index = begin;

    while (left <= right)
    {
        while (a[left] < pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            index = a[left];
            a[left] = a[right];
            a[right] = index;
            left++;
            right--;
        }
    }
    if (left > k)
    {
        GetNumber(a, begin, left, k);
    }
    if (k > left)
    {
        GetNumber(a, left, end, k);
    }
    if (k == left)
    {
        printf("第k大的数为 %d\n", index);
        return;
    }
}

// 快速排序（随机）
void RandQuickSort(int *a, int begin, int end)
{
    int pivot = a[rand() % (end + 1)] + begin;
    int left = begin, right = end;
    int index = begin;
    while (left <= right)
    {
        while (a[left] < pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            index = a[left];
            a[left] = a[right];
            a[right] = index;
            left++;
            right--;
        }
    }

    if (left < end)
    {
        QuickSort_Recursion(a, left, end);
    }
    if (begin < right)
    {
        QuickSort_Recursion(a, begin, right);
    }
}

// 冒泡排序三个优化
void BubbleSort(int *a, int size)
{
    int left = 0, right = size - 1;
    int lastSwapIndex = 0; // 记录最后一次交换的位置
    int flag = 0;          // 标志

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                Swap(&a[i], &a[i + 1]);
                flag = 1;
                lastSwapIndex = i;
            }
        }
        right = lastSwapIndex;
        if (!flag)
        {
            break;
        }
        flag = 0;
        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                Swap(&a[i], &a[i - 1]);
                flag = 1;
                lastSwapIndex = i;
            }
        }
        left = lastSwapIndex;
        if (!flag)
        {
            break;
        }
        flag = 0;
    }
}

void Show()
{
    printf("*********排序算法**********\n");
    printf("1.插入排序\n");
    printf("2.归并排序\n");
    printf("3.快速排序（递归版）\n");
    printf("4.快速排序（非递归版）\n");
    printf("5.快速排序（枢轴存放）\n");
    printf("6.快速排序（随机）\n");
    printf("7.计数排序\n");
    printf("8.基数计数排序\n");
    printf("9.颜色排序\n");
    printf("10.在一个无序序列中找到第K大/小的数\n");
    printf("11.冒泡排序三个优化\n");
    printf("12.退出\n");
}
