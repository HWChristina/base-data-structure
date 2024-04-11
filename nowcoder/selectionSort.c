#include "stdio.h"

//开辟有限几个变量时，空间复杂度也只是O(1)
void swap(int* arr,int i,int j){
    int tmp=arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void selectionSort(int *arr,int sz){
    if(arr ==NULL|| sz<2){
        return;
    }
    for(int i=0;i<sz-1;i++){
        int minindex = i;
        for(int j=i+1;j<sz;j++){
            minindex = arr[j]<arr[minindex]?j:minindex;
        }
        swap(arr,i,minindex);
    }

}

void main(){
    int arr[] = {3,2,1,5,7,10};
    int length = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,length);
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
}