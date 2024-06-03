//插入排序 时间复杂度O(N²)，空间复杂度O(1)
#include "stdio.h"
#include "stdlib.h"

//j:当前数字的前一个位置，arr[j]当前数字的前一个位置的数字，直至j换到不能再往前为止停。

void swap(int* arr,int i,int j){
    //要确保ij不指向数组同一位置才行
    arr[i]=arr[i]^arr[j];
    arr[j]=arr[i]^arr[j];
    arr[i]=arr[i]^arr[j];
}
void insertSort(int* arr,int sz){
    if(arr==NULL||sz<2){
        return;
    }
    for(int i=1;i<sz;i++){
        for(int j=i-1;j>=0 && arr[j]>arr[j+1];j--){
            swap(arr,j,j+1);
        }
    }
}

void main(){
    int arr[] = {3,2,1,5,7,10};
    int length = sizeof(arr)/sizeof(arr[0]);
    insertSort(arr,length);
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
}
