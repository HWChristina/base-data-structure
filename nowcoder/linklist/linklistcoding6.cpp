// 两个链表相交，找到第一个相交节点（内存地址一致）并返回
// 面试要求：时间复杂度：O(N);额外空间复杂度：O(1)
#include <iostream>
#include "stdlib.h"
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
};

// 利用快慢指针获得入环节点
Node *getLoopNode(Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return NULL;
    }
    Node *n1 = head->next;
    Node *n2 = head->next->next;
    while (n1 != n2)
    {
        if (n2->next == NULL || n2->next->next == NULL)
        {
            return NULL;
        }
        n1 = n1->next;
        n2 = n2->next->next;
    }
    n2 = head;
    while (n1 != n2)
    {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}

Node *noLoop(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    Node *cur1 = head1;
    Node *cur2 = head2;
    int n = 0;
    // 找到head1、head2的尾部元素
    while (cur1->next != NULL)
    {
        n++;
        cur1 = cur1->next;
    }
    while (cur2->next != NULL)
    {
        n--;
        cur2 = cur2->next;
    }
    // 注意比较的是两个节点的内存地址
    if (cur1 != cur2)
    {
        return NULL;
    }
    // 谁长，谁的头变成cur1;谁短，谁的头变成cur2
    cur1 = n > 0 ? cur1 : cur2;
    cur2 = cur1 == head1 ? head2 : head1;
    n = abs(n);
    while (n != 0)
    {
        n--;
        cur1 = cur1->next;
    }
    while (cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

// bothLoop 两个都是有环单链表loop1/2:利用getloop得到首个入环节点
Node *bothLoop(Node *head1, Node *loop1, Node *head2, Node *loop2)
{
    Node *cur1 = NULL;
    Node *cur2 = NULL;
    if (loop1 == loop2)
    {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1)
        {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2)
        {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? cur1 : cur2;
        cur2 = cur1 = head1 ? head2 : head1;
        n = abs(n);
        // 减去多出去的长度n = |n1-n2|
        while (n != 0)
        {
            n--;
            cur1 = cur1->next;
        }
        // 共同向入环节点走
        while (cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    else
    {
        cur1 = loop1->next;
        while (cur1 != loop1)
        {
            if (cur1 == loop2)
            {
                return loop1;
            }
            cur1 = cur1->next;
        }
        return NULL;
    }
}

// 主函数调用函数
Node *getIntersectNode(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    Node *loop1 = getLoopNode(head1);
    Node *loop2 = getLoopNode(head2);
    if (loop1 == NULL && loop2 == NULL)
    {
        return noLoop(head1, head2);
    }
    if (loop1 != NULL && loop2 != NULL)
    {
        return bothLoop(head1, loop1, head2, loop2);
    }
    return NULL;
}

int main(){
    Node* head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(3);
    Node* head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(5);
    head2->next->next->next = new Node(3);
    Node* firstPublicNode = getIntersectNode(head1,head2);
    while(firstPublicNode!=NULL){

        cout<<firstPublicNode->value<<endl;
    }
    
    return 0;
}

