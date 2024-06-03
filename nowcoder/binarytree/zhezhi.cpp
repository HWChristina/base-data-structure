//微软面试原题 打印所有折痕

#include "iostream"
#include "string"
using namespace std;

//递归过程，来到了某一个节点
//i是当前节点的层数，N是一共的层数
//二叉树中序遍历
//down==true：凹折痕；down==false：凸折痕
void printProcess(int i, int N,bool down){
    if(i>N){
        return ;
    }
    //中序遍历过程 在中间位置打印
    printProcess(i+1,N,true);
    //down = down? "凹":"凸";
    cout<<down? "凹":"凸";
    printProcess(i+1,N,false);
}

void printAllFolds(int N){
    printProcess(1,N,true);
}
//输出结果1代表凹，0代表凸
int main(string arg){
    int N = 3;
    printAllFolds(N);
    return 0;
}

