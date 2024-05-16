//打印两个有序链表的公共部分
#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node(int val):value(val),next(nullptr){}
};

Node* publicPart(Node* head1,Node* head2){
    Node* cur1 = head1;
    Node* cur2 = head2;
    Node* temp = NULL;
    while(cur1!=NULL||cur2!=NULL){
        if(cur1->value==cur2->value){
            temp = new Node(cur1->value);
            
        }
    }

}