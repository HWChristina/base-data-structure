#include <stdio.h>
#include "stdlib.h"
#include "limits.h"
#include "math.h"

//实际代码中没有桶，是按照词频表来实现的

//count需要前缀和
//基数排序

int getMAX(int* arr,int sz){
    int i;
    int max = arr[0];
    //int length = sizeof(arr)/sizeof(int);
    for(i=1;i<sz;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

//找到最大值有res个十进制位
int maxbits(int* arr,int sz){
    //int length = sizeof(arr)/sizeof(int);
    //先设置最大值为系统最小
    int max=INT_MIN;
    max = getMAX(arr,sz);
    int res = 0;
    while(max!=0){
        res++;
        max/=10;
    }
    return res;
}
//取出当前数组元素d进制位的数。e.g.arr[2]=072;d=1时，getdigit返回的是2.
int getDigit(int x,int d){
    return ((x/((int)pow(10,d-1)))%10);
}
//基数排序
//digit:数组内最大值有多少个十进制位
void radixSort(int* arr,int L,int R,int digit){
    const int  radix =10;
    int i = 0; int j = 0;
    //定义辅助空间
    int* bucket =(int*)malloc(sizeof(int)*(R-L+1));
    //int* a = bucket;
    if(bucket==NULL){
        return;
    }
    for(int d=1;d<=digit;d++){
        //10个空间
        //count里每个位置下标表示数字，存储的是(0,i)的前缀和(<=i)
        /* 注意：使用此语句会出现segmentation fault越界问题！具体原因未知！
        //int* count =(int*)malloc(sizeof(int)*(radix));  */
        int count[10]={0}; 
        /*  if(count==NULL){
           return;
        }  */
        for(i=L;i<=R;i++){
            j = getDigit(arr[i],d);//取出要处理的进制位内的数
            count[j]++;
        }
        //求前缀和
        for(i=1;i<radix;i++){
            count[i] = count[i] + count[i-1];
        }
        //从数组右往左(先入桶的先出桶)，根据count数组的值输出到备用数组中去，相当于完成了一次入桶出桶操作。
        for(i=R;i>=L;i--){
            //j表示当前数组arr[]中第i位置上的数所要处理的d进制位的数字。
            j= getDigit(arr[i],d);
            bucket[count[j]-1]=arr[i];
            count[j]--;
        }
        
        //将备用数组内的元素拷贝回原数组
        for(i=L,j=0;i<=R;i++,j++){
            arr[i]=bucket[j];
        }
    /* free(count);
    count=NULL; */
    } 
    free(bucket);
    //bucket=NULL;
}


void rSort(int* arr,int sz){
    //int length = sizeof(arr)/sizeof(int);
    if(arr==NULL||sz<2){
        return;
    }
    radixSort(arr,0,sz-1,maxbits(arr,sz));
}

int main(){

    int arr[] = {100,16,25,73,44,1028,30};
    int length = sizeof(arr)/sizeof(arr[0]);
    rSort(arr,length);
    for(int i = 0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
    int h = 7%10;
    printf("%d",h);
    printf("\n");
    return 0;
}
