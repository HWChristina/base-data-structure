///*判断一个二叉树是否为完全二叉树（两种方法）
#include "iostream"
#include "math.h"
#include "algorithm"
#include "queue"
using namespace std;
// 定义二叉树节点结构
struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};
/*----------------- 法1：利用树形DP递归套路完成--------------------*/
// 1.定义一个需要返回的结构体类型的数据
// 子树需要向上提供的信息：
/*（1）子树的高度（2）子树是否是完全二叉树（3）子树是否是满二叉树*/
struct returnType3
{
    bool CBT;
    bool FBT;
    int height;
    returnType3(bool CB, bool FB, int h) : CBT(CB), FBT(FB), height(h) {}
};

// 2.设计递归结构
returnType3 process2(Node *x)
{
    // 考虑初始状况
    if (x == NULL)
    {
        return new returnType3(true, true, 0);
    }
    //
    returnType3 leftData = process2(x->left);
    returnType3 rightData = process2(x->right);
    // 先假设当前树是完全二叉树
    bool CBT = false;
    // 开始设计本层的信息
    // 分情况及条件考虑
    bool FBT = false;
    int height = (std::max(leftData.height, rightData.height)) + 1;
    // 定CBT的值
    //  1.左右的高度相同，分为左满右满、左满右完全
    if (
        (leftData.height == rightData.height) &&
        (leftData.FBT && rightData.FBT))
    {
        FBT = true;
        CBT = true;
    }
    if (
        (leftData.height == rightData.height) &&
        (leftData.FBT && rightData.CBT))
    {
        CBT = true;
    }
    // 2.左边的高度=右边高度+1，同时分为左完全右满、左满右满
    if (
        (leftData.height == rightData.height + 1) &&
        (rightData.FBT && leftData.CBT))
    {
        CBT = true;
    }
    if (
        (leftData.height == rightData.height + 1) &&
        (rightData.FBT && leftData.FBT))
    {
        CBT = true;
    }
    return new returnType3(CBT, FBT, height);
}
// 3.调用递归函数2
bool CBT(Node*head){

    return process2(head).CBT;

}
/*----------------------法1 结束-----------------------------*/


/*----------------法2：利用完全二叉树的特性解题------------------*/
// 利用队列的数据结构+宽度优先遍历的过程
bool isCBT(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    queue<Node *> queue;
    // Node* cur = head;
    queue.push(head);
    Node *l = nullptr;
    Node *r = nullptr;
    // 定义一个事件标志位leaf，用于标定是否遇到第一个左右孩子不全的节点
    bool leaf = false;
    // 需要让树向下继续遍历
    while (!queue.empty())
    {
        head = queue.front();
        queue.pop();
        l = head->left;
        r = head->right;
        // 条件2：如果遇到了不双全的节点之后，又发现当前节点居然有孩子
        if ((leaf && (l != NULL || r != NULL)) // 条件2：已遇到左右不双全节点，当前head节点应为叶子节点。
            ||
            (l == NULL && r != NULL) // 条件1：孩子有右无左
        )
        {
            return false;
        }
        if (l != NULL)
        {
            queue.push(l);
        }
        if (r != NULL)
        {
            queue.push(r);
        }
        if (l == NULL || r == NULL) // 孩子不双全
        {
            leaf = true;
        }
    }
    return true;
}
