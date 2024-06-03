#include "stdio.h"
#include "stdlib.h"
#include <string.h>
//位运算--在数组中找到出现奇数次的两个数
void printOddTimesNum2(int arr[],int length){
   int eor = 0;
   
   for(int i = 0;i< length;i++){
      eor ^=arr[i];
   }
   //eor = a^b;eor!=0;-->eor必定有一个位置是1
   int rightone = eor&(~eor+1); //提取出最右的1
   int onlyone = 0; //eor'=onlyone=a or b;-->eor异或完最右的不是1(a)或是1(b)所有数之后的结果
   for(int cur=0;cur<length;cur++){
    if((arr[cur] & rightone)==0){
        onlyone ^= arr[cur];    //onlyone=a/b eor^onlyone=a/b^a^b
    }
   }
   printf("%d,%d\n",onlyone,eor^onlyone);
   
   //+" "+(eor^onlyone)

}
void main(){
    int arr[] ={1,2,2,1,3,3,3,8,8,7,7,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    printOddTimesNum2(arr,len);
    //printf("hello world!");
}