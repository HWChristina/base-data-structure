#include "stdio.h"
#include "stdlib.h"
#include <string.h>


int merge(int* arr,int* help,int L,int m,int R){

    int length = R-L+1;
    int i=0;
    int p1=L;
    int p2=m+1;
    int res = 0;    //求小和问题  (L)p1...p2...(R)
    while(p1<=m&&p2<=R){ 
        res += (arr[p1]<arr[p2])?(R-p2+1)*arr[p1]:0;
//与mergeSort的区别是，当p1p2指向的数相等时，优先拷贝右边的数，所以是小于不是小于等于。
        help[i++]=arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=m)  //p2越界
    {
        help[i++]=arr[p1++];
    }
    while(p2<=R)  //p1越界
    {
        help[i++]=arr[p2++];
    }
    for(int i=0; i<length;i++){
        arr[L+i]=help[i];
    }
    return res;
}
int process(int* arr,int* help,int L,int R)
{
    if(L==R)
    {
        return 0;
    }
    //右移一位相当于除以2、效率更高
    int mid = L+((R-L)>>1);     
    return process(arr,help,L,mid)+
           process(arr,help,mid+1,R)+
           merge(arr,help,L,mid,R);
}
 int xiaohe(int* arr,int L,int R){
    int* help = (int*)malloc(sizeof(int)*(R-L+1));
    int length = R-L+1;
    if(arr==NULL || length<2){
        return 0;
    }
    return process(arr,help,0,length-1);
    free(help);
}
void print(int* arr,int sz){
    for(int i=0;i<sz;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {1,3,4,2,5};
    int length = sizeof(arr)/sizeof(int);
    print(arr,length);
    int ces = xiaohe(arr,0,length-1);
    print(arr,length);
    printf("%d\n",ces);
}