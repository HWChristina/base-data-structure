/*树型DP问题（二叉树的递归套路）
可解决的二叉树是否为平衡二叉树、搜索二叉树、满二叉树的判定问题
*/
#include "iostream"
#include "algorithm"
#include "math.h"

using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};
/*--------------- 二叉树是否是平衡二叉树-----------------*/
// 1.定义一个左右子树需要返回所有数据信息都包括的类（构造函数）
class returnType1
{
public:
    bool isBalanced;
    int height;
    returnType1(bool isB, int hei) : isBalanced(isB), height(hei) {}
};
// 2.定义主函数调用的递归函数，返回判定是否平衡的需要的结果信息
returnType1 process(Node *x)
{
    if (x == NULL)
    {
        // 高度在赋初值的时候已经设为0，后续随着递归过程会逐渐递增
        return returnType1(true,0);
    }
    returnType1 leftData = process(x->left);
    returnType1 rightData = process(x->right);
    int height = std::max(leftData.height, rightData.height) + 1;
    bool isBalanced = leftData.isBalanced && rightData.isBalanced && abs(rightData.height - leftData.height) < 2;
    return returnType1(isBalanced, height);
}
// 3.主函数调用递归函数
bool isbalanced(Node *head)
{
    return process(head).isBalanced;
}
/*-----------------二叉树是否是平衡二叉树---------------*/
//
//
//
/* --------------判断一个二叉树是否为搜索二叉树----------*/
// 1.定义一个左右子树需要返回的所有信息（min,max,isBST）
class returnType2
{
public:
    int min;
    int max;
    bool isBST;
    returnType2(int mi, int ma, bool isf) : min(mi), max(ma), isBST(isf) {}
};

// 2.定义递归
returnType2* process1(Node *head)
{
    // 首先设定初始状况,由于最大最小值没办法设定初始值，所以直接返回null；
    if (head == NULL)
    {
        return nullptr;
    }
    // 左右子树分别提供信息
    returnType2* leftData = process1(head->left);
    returnType2* rightData = process1(head->right);
    // 根据各种条件考虑，设定返回结构内各自的值
    // 最大最小值设定,注意:还需要与当前的节点的value比较
    // head左右子树提供的信息是空的话直接返回自己的value，注意：左右子树只能提供信息
    // 设定min/max初始值为head->value的值
    int min = head->value;
    int max = head->value;
    // 条件1
    if (leftData != NULL)
    {
        max = std::max(leftData->max, max);
        min = std::min(leftData->min, min);
    }
    if (rightData != NULL)
    {
        max = std::max(max, rightData->max);
        min = std::min(min, rightData->min);
    }
    // 条件2
    bool isBST = true;
    if (leftData != NULL && (leftData->isBST == false || leftData->max > head->value))
    {
        isBST = false;
    }
    if (rightData != NULL && (rightData->isBST == false || rightData->min < head->value))
    {
        isBST = false;
    }
    /*条件2 写法2
    bool isBST = false;
    if(
        (leftData!=NULL?(leftData.isBST && leftData.max<x.value):true)
        &&
        (rightData!=NULL?(rightData.isBST && rightData.min>x.value):true)
    ){
        isBST=true;
    }
    */
    return new returnType2(min, max, isBST);
}
// 3.主函数调用（只需返回是否为搜索二叉树即可）
bool issearchTree(Node *head)
{

    return process1(head)->isBST;
}
/* -------------判断一个二叉树是否为搜索二叉树----------*/
//
//
//
/* -------------（Han）方法1：判断一个二叉树是否为满二叉树----------*/
// 1.先定义向上传递消息的结构体
struct returnType3
{
    bool FBT;
    int height;
    returnType3(bool FB, int high) : FBT(FB), height(high) {}
};

// 2.定义递归体结构
returnType3 process2(Node *head)
{
    if (head == NULL)
    {
        return returnType3(true,0);
    }
    returnType3 leftData = process2(head->left);
    returnType3 rightData = process2(head->right);

    bool FBT = false;
    if (
        (leftData.FBT && rightData.FBT) 
        && 
        (leftData.height == leftData.height))
    {
        FBT=true;
    }
    int height = std::max(leftData.height, rightData.height) + 1;

    return returnType3(FBT, height);
}
//3.定义主函数调用函数
bool isFBT(Node* head){
    if(head==NULL){
        return true;
    }
    return process2(head).FBT;
}
/* -------------（左程云）方法2：判断一个二叉树是否为满二叉树----------*/
class returnType4{
public:
    int nodes;
    int height;
    returnType4(int n,int h):nodes(n),height(h){}
};
//2.递归结构
returnType4 process3(Node* head){
    if(head==nullptr){
        return returnType4(0,0);
    }
    returnType4 leftData = process3(head->left);
    returnType4 rightData = process3(head->right);
    int nodes = leftData.nodes+rightData.nodes+1;
    int height = std::max(leftData.height,leftData.height)+1;
    return returnType4(nodes,height);
}
//3.主函数调用函数
bool isFBT1(Node* head){
    if(head==NULL){
        return true;
    }
    int height = process3(head).height;
    int nodes = process3(head).nodes;
    return nodes==1<<height;
}

int main(){
    return 0;
}
