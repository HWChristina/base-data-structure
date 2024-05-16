/*复制含有随机指针节点的链表（时间复杂度O(N),空间复杂度O(1)）
//笔试方法：运用哈希表 
//面试方法：用极个别的指针变量实现 
*/
#include "iostream"
#include "unordered_map"

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *random;
    Node(int val) : value(val), next(nullptr), random(nullptr)
    {
    }
};
//利用哈希表
Node *copyListWithRand1(Node *head)
{

    unordered_map<Node *, Node *> hmap;
    Node *cur = head;
    while (cur != NULL)
    {
        Node *copy = new Node(cur->value);
        hmap[cur] = copy;
        // hmap.insert(cur,copy);
        cur = cur->next;
    }
    cur = head;

    while (cur != NULL)
    {

        // hmap.at(cur)->next=hmap.at(cur->next);
        hmap[cur]->next = hmap[cur->next];
        // hmap.at(cur)->random=hmap.at(cur->random);
        hmap[cur]->random = hmap[cur->random];
        cur = cur->next;
    }
    return hmap[head]; // 输出的value即是复制后的新链表
}
//利用位置对应关系
Node* copyListWithRand2(Node* head){
    if(head==NULL){
      return NULL;
    }
    Node* cur=head;
    Node* next=NULL;
    //将所有元素的复制元素都放在后面
    while (cur!=NULL){
        next=cur->next;
        //Node* copy=
        cur->next=new Node(cur->value);
        cur->next->next=next;
        cur=next;
    }
    cur=head;
    //设置克隆节点的rand指针
    Node*curCopy=NULL;
    while(cur!=NULL){
        next=cur->next->next;
        curCopy=cur->next;
        curCopy->random=cur->random!=NULL?cur->random->next:NULL;
        cur=next;
    }
    Node* res=head->next;
    cur = head;
    //分离原链表与克隆链表
    while(cur!=NULL){
        next=cur->next->next;
        curCopy=cur->next;
        cur->next=next;
        curCopy->next=next!=NULL?next->next:NULL;
        cur=next;
    }
    //返回新链表头
    return res;

}



// 打印哈希表中的对应关系
void printUnordered_map(unordered_map<Node *, Node *> m)
{
    for (unordered_map<Node *, Node *>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << it->first->value << "value:" << it->second->value << endl;
    }
    cout << endl;
}

// 打印链表
void printLinkList(Node *head)
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
int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    a->next = b;
    b->next = c;
    a->random = c;
    b->random = a;
    c->random = b;

    // 复制链表
    Node *copyhead = copyListWithRand1(a);

    std::unordered_map<Node *, Node *> m;
    m[a] = copyhead;
    m[b] = copyhead->next;
    m[c] = copyhead->next->next;

    // 打印哈希表新旧链表关系
    printUnordered_map(m);
    // 打印新链表
    printLinkList(copyhead);
    // 释放链表空间
    delete a;
    delete b;
    delete c;
    delete copyhead;
    return 0;
}
