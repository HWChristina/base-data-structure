// 反转单向和双向链表(时间复杂度为O(N),额外空间复杂度O(1))

#include <iostream>
using namespace std;
/* typedef struct Node{
    int value;
    Node* next;
}Node; */

class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
};

typedef struct DoubleLinkList
{
    /* data */
    int value;
    DoubleLinkList *prev;
    DoubleLinkList *next;
    DoubleLinkList(int val) : value(val), prev(nullptr), next(nullptr) {}

} DNode;

Node *reverseList(Node *head)
{
    Node *m = NULL;
    Node *n = NULL;
    Node *cur = head;
    // 断链前先保存下一个节点
    while (cur != NULL)
    {
        n = m;
        m = cur;
        cur = cur->next;
        m->next = n; // 下一次循环再重连前一个元素
    }
    return m;
}

DNode *reverseDoubleLinkList(DNode *head)
{

    DNode *p = NULL;
    DNode *q = NULL;
    while (head != NULL)
    {
        q = head ->next;
        head->next = p;
        head->prev = q;
        p = head;
        head = q;
    }
    return p;
}

// 打印链表
void printList(Node *head)
{
    Node *cur = head;

    while (cur != NULL)
    {
        cout << cur->value << "->";
        cur = cur->next;
    }
    cout << "NULL" << endl;
    return;
}

// 打印双向链表
void printDoubleList(DNode *head)
{
    DNode *cur = head;
    while (cur != NULL)
    {
        cout << cur->value << "<->";
        cur = cur->next;
    }
    cout <<"NULL"<< endl;
}

int main()
{
    // 新建单链表
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(5);
    Node *cur = reverseList(head);
    printList(cur);
    // 新建双向链表
    DNode *Dhead = new DNode(4);
    Dhead->next = new DNode(3);
    //Dhead->prev = NULL;
    Dhead->next->next = new DNode(1);
    //Dhead->next->prev = Dhead;
    DNode *DCur = reverseDoubleLinkList(Dhead);
    printDoubleList(DCur);
    return 0;
}
