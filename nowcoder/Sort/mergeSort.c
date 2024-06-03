#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void print(int* arr,int sz)
{
    for(int i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//归并排序
void merge(int* arr,int* help,int L,int M,int R)
{
    int len=R-L+1;
    int i = 0;
    int P1 = L;
    int P2 = M+1;
    while(P1<=M && P2<=R){
        help[i++]=arr[P1]<=arr[P2] ? arr[P1++]:arr[P2++];
    }
    while (P1<=M)     //P2越界
    {
        help[i++]=arr[P1++];
    }
    while(P2<=R){     //P1越界
        help[i++]=arr[P2++];
    }
    for(i=0;i<len;i++){    //拷贝所有元素到arr
        
        arr[L+i]=help[i];
        //arr[i]=help[i];
    }
    
}
//递归
void process(int* arr,int* help,int L,int R)
{
    if(L==R)
    {
        return;
    }
    
    int mid = L+((R-L)>>1);   //将除以2的运算转变成右移运算
    
    process(arr,help,L,mid);
    process(arr,help,mid+1,R);
    merge(arr,help,L,mid,R);

    }

void mergeSort(int* arr,int L,int R){
    
    
    int* help=(int*)malloc(sizeof(int)*(R-L+1));
    if(help==NULL)
    {
        printf("malloc false!\n");
        exit(-1);
    }
    process(arr,help,L,R);

    free(help);

}


int main()
{   
    int array[]={2,1,5,4,3,7,9,6};
    int length = sizeof(array)/sizeof(int);
    //arr占用内存大小除以int型占用大小，即为arr中包含int元素的个数。
    //print(array,sizeof(array)/sizeof(int));
    print(array,length);
    mergeSort(array,0,length-1);
    //归并排序后
    print(array,length);
    return 0;
}