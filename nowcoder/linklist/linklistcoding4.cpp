// 按照某值划分为左边小、中间相等、右边大的形式
#include "iostream"

using namespace std;

struct Node
{
    int value;
    struct Node *next;
    Node(int val) : value(val), next(nullptr) {}
};

Node *listPartition2(Node *head, int pivot)
{
    Node *sH = NULL;
    Node *sT = NULL;
    Node *eH = NULL;
    Node *eT = NULL;
    Node *bH = NULL;
    Node *bT = NULL;
    Node *next = NULL; // save next node
    while (head != NULL)
    {
        next = head->next; // 保留链表下一个节点位置
        head->next = NULL; // 链表当前节点断链
        if (head->value < pivot)
        {
            if (sH == NULL)
            {
                sH = head;
                sT = head;
            }
            else
            {
                sT->next = head;
                sT = head;
            }
        }
        else if (head->value == pivot)
        {
            if (eH == NULL)
            {
                eH = head;
                eT = head;
            }
            else
            {
                eT->next = head; // 将当前head元素加进数组
                eT = head;       // eT后移到链表末端
            }
        }
        else
        {
            if (bH == NULL)
            {
                bH = head;
                bT = head;
            }
            else
            {
                bT->next = head;
                bT = head;
            }
        }
        head = next;
    }
    if (sT != NULL)
    {
        sT->next = eH;
        eT = eT == NULL ? sT : eT; // 下一步 谁去连大于区域的头，谁就变成eT
    }
    // 不管上面if重连与否 所有链表再重连
    if (eT != NULL)
    {
        eT->next = bH;
    }
    return sH != NULL ? sH : (eH != NULL ? eH : bH);

    /*      if(sH!=NULL&&eH!=NULL){
            sT->next=eH;
         }
         if(eH!=NULL&&bH!=NULL){
            eT->next=bH;
         } */
}

// 打印链表
void printNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

// 创建一个实例链表进行测试
int main()
{
    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(2);
    printNode(head);
    Node *result = listPartition2(head, 6);
    printNode(result);

    // 释放链表内存
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    return 0;
}
