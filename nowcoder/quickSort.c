#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"


void swap(int* arr,int L,int R){
    //异或运算可以交换两个不同内存位置的值
    //交换的数组内的值 不是指针位置
    int temp = arr[L];
    arr[L] = arr[R];
    arr[R] = temp;
}
int* partition(int* arr,int L,int R){

     int* p = (int*)malloc(sizeof(int)*2);
     int less = L-1; //＜区域的右边界
     int more = R;   //＞区域的左边界
     while(L<more){   //
        if(arr[L]<arr[R]){
            swap(arr,++less,L++);
        }else if(arr[L]>arr[R]){
            //交换后，先不动，还要再进行比较
            swap(arr,--more,L);
        }else{
            L++;
        }
     }
     swap(arr,more,R);
     //返回一个新数组
     p[0] = less+1;
     p[1] = more;
     return p;
}
//给arr数组排好序利用递归
void sort(int* arr,int L,int R)
{
    //产生随机数的种子  
    srand((unsigned)time(NULL));      
    if(L<R){
        //交换函数，产生[0,R-L]内的随机数，+L之后范围变为[L,R]之间
        swap(arr,L+(int)(rand()%(R-L+1)),R);
        int *p1 = partition(arr, L, R);
        sort(arr,L,p1[0]-1);  //<区
        sort(arr,p1[1]+1,R);  //>区
    }
} 
//处理函数，对数组划分，分出随机数的<边界，=边界，>边界
//注意：c语言里不能直接返回数组，需要使用一个过渡方法！

void quickSort(int* arr,int sz){
    //int length = sizeof(arr)/sizeof(int);
    if(arr==NULL || sz<2){
      return;
    }
    sort(arr,0,sz-1);
}
int main(){

    int arr[] = {1,2,4,5,3,8,7,9,3,16};
    int length = sizeof(arr)/sizeof(int);
    quickSort(arr,length);
    for(int i = 0;i<length;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    return 0;


}