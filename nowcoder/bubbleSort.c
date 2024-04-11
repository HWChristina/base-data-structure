#include <stdio.h>
#include "stdlib.h"

//交换arr的i和j位置上的值
void swap(int* arr,int i,int j){
    arr[i] = arr[i]^arr[j];
    arr[j] = arr[i]^arr[j];
    arr[i] = arr[i]^arr[j];
}

void bubbleSort(int* arr,int sz){
    if(arr==NULL||sz<2){
        return;
    }
    for(int e=sz-1;e>0;e--){
        for(int i=0;i<e;i++){
            if(arr[i]>arr[i+1]){
                swap(arr,i,i+1);
            }
        }
    }
}



void main(){
    int arr[] = {3,2,1,5,7,10};
    int length = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,length);
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    //printf("\n");
}