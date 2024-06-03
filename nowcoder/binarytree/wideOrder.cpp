/* 
代码实现：
 1.利用队列数据结构对二叉树进行宽度优先遍历
 2.求解二叉树的最大宽度函数（利用哈希表）
*/
#include <iostream>
#include <queue>
#include "unordered_map"
#include "limits.h"
#include "algorithm"

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left;
    Node *right;
    Node(T value) : value(value), left(nullptr), right(nullptr) {}
};
template <typename T>
void wideOrder(Node<T> *head)
{
    if (head == NULL)
    {
        return;
    }
    queue<Node<T> *> queue;
    queue.push(head);
    while (!queue.empty())
    {
        Node<T> *cur = queue.back();
        queue.pop();
        cout << cur->value << endl;
        if (cur->left != NULL)
        {
            queue.push(cur->left);
        }
        if (cur->right != NULL)
        {
            queue.push(cur->right);
        }
    }
}
// 求解二叉树内最宽的层包含节点数MAX
template <typename T>
int Maxwide(Node<T> *head)
{
    if (head == NULL)
    {
        return 0;
    }
    queue<Node<T> *> queue;
    queue.push(head);
    unordered_map<Node<T>*, int> levelmap;
    levelmap.insert(make_pair(head,1));
    //levelmap[head] = 1;
    int curLevel = 1;
    int curLevelNodes = 0;
    int max = INT_MIN;
    while (!queue.empty())
    {
        Node<T> *cur = queue.front();        // 返回栈顶元素
        queue.pop();                         // 弹出首个队列元素
        int curNodeLevel = levelmap.at(cur); // 返回cur的key值
        if (curNodeLevel == curLevel)
        {
            curLevelNodes++;
        }
        else
        {
            max = std::max(max,curLevelNodes);
            curLevel++;
            curLevelNodes = 1;
        }
        if (cur->left != NULL)
        {
            levelmap.insert(make_pair(cur->left, curNodeLevel + 1));
            queue.push(cur->left);
        }
        if (cur->right != NULL)
        {
            levelmap.insert(make_pair(cur->right, curNodeLevel + 1));
            queue.push(cur->right);
        }
    }
    return max;
}

int main()
{

    Node<int> *head;
    head = new Node<int>(1);
    head->left = new Node<int>(2);
    head->right = new Node<int>(3);
    head->left->left = new Node<int>(4);
    head->right->left = new Node<int>(5);
    head->right->right = new Node<int>(6);
    head->left->left->right = new Node<int>(7);
    int Max = Maxwide(head);
    cout<<Max<<endl;
    return 0;
}

// 每层何时收集何时结算、、、
// 当节点弹出时结算curLevelNode
// 保证每个节点进入队列时已经记录了层数
