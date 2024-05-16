/* 
代码实现：
1.先序、中序、后序遍历非递归方式实现（利用栈数据结构）
2.打印一颗二叉树 
*/

#include <iostream>
#include <stdlib.h>
#include <stack>
#include "string"

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

// 先序遍历非递归
void preOrderUnRecur(Node<T> *head)
{
    cout << "pre-order:" << endl;
    if (head != NULL)
    {
        stack<Node<T> *> stack;
        stack.push(head);

        while (!stack.empty())
        {
            head = stack.top(); // 取栈顶元素
            stack.pop();        // 弹出栈顶元素
            cout << head->value << " ";
            if (head->right != NULL)
            {
                stack.push(head->right);
            }
            if (head->left != NULL)
            {
                stack.push(head->left);
            }
        }
    }
    cout << endl;
}
// 后序遍历非递归
template <typename T>
void posOrderUnRecur(Node<T> *head)
{
    cout << "pos-order:" << endl;
    if (head != NULL)
    {
        stack<Node<T> *> s1;
        stack<Node<T> *> s2; // 收集栈
        s1.push(head);
        while (!s1.empty())
        {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if (head->left != NULL)
            {
                s1.push(head->left);
            }
            if (head->right != NULL)
            {
                s1.push(head->right);
            }
        }
        while (!s2.empty())
        {
            Node<T> *data = s2.top();
            s2.pop();
            cout << data->value << " ";
        }
    }
    cout << endl;
}
// 中序遍历非递归
template <typename T>
void inOrderUnRecur(Node<T> *head)
{
    cout << "in-order:" << endl;
    if (head != NULL)
    {
        stack<Node<T> *> stack;
        while (!stack.empty() || head != NULL)
        {
            // 整棵树（包含所有子树）的左边界进栈
            if (head != NULL)
            {
                stack.push(head);
                head = head->left;
            }
            else
            {
                head = stack.top();
                stack.pop();
                cout << head->value << " "; // 依次弹出的过程中打印
                head = head->right;
            }
        }
    }
    cout << endl;
}
// 打印一颗完整的二叉树
string getSpace(int num)
{
    string space = " ";
    string buf = " ";
    for (int i = 0; i < num; i++)
    {
        buf.append(space);
    }
    return buf;
}
template <typename T>
void printInOrder(Node<T> *head, int height, string to, int len)
{
    if (head == NULL)
    {
        return;
    }
    //箭头分别指向各自的头结点方向v2v表示2的头结点靠左下方。
    printInOrder(head->right, height + 1, "v", len);
    string val = to + to_string(head->value) + to;
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) + val <<endl;
    printInOrder(head->left, height + 1, "^", len);
}
template <typename T>
void printTree(Node<T> *head)
{
    cout << "Binary Tree:" << endl;
    printInOrder(head, 0, "H", 7);
    cout << endl;
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
    printTree(head);
    preOrderUnRecur(head);
    posOrderUnRecur(head);
    inOrderUnRecur(head);

    return 0;
}