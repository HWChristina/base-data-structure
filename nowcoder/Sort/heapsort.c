#include "stdio.h"
#include "stdlib.h"

void swap(int *arr, int L, int R)
{
    int temp = arr[L];
    arr[L] = arr[R];
    arr[R] = temp;
}
// 向上比
void heapInsert(int *arr, int index)
{
    //(index-1)/2结果是0，不越界，需要注意
    while (arr[index] > arr[(index - 1) / 2])
    {
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}
// 向下比
void heapify(int *arr, int index, int heapSize)
{
    int left = index * 2 + 1;
    while (left < heapSize)
    {
        // 两个孩子中，谁的值较大，把下标给largest
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        // 父和较大的孩子之间，谁的值大，把下标给largest
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index)
        {
            break;
        }
        swap(arr, largest, index);
        index = largest;
        left = index * 2 + 1;
    }
}
// 空间复杂度O(1)
void heapsort(int *arr)
{

    int length = sizeof(arr) / sizeof(int);

    if (arr == NULL || length < 2)
    {
        return;
    }
    // 把数组整体范围变为大根堆heapsize++的过程 时间复杂度O(N*logN)
    for (int i = 0; i < length; i++)
    {
        heapInsert(arr, i);
    }
    /*  更快捷的办法：直接使用heapify自下向上变为大根堆 时间复杂度O(N)
         for(int i=length-1;i>=0;i--){
            heapify(arr,i,length);
        } */
    int heapSize = length;
    swap(arr, 0, --heapSize);
    while (heapSize > 0)
    {                              // O(N)
        heapify(arr, 0, heapSize); // O(logN)
        swap(arr, 0, --heapSize);  // O(1)
    }
}
