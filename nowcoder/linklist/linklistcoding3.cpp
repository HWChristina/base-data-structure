//判断单链表是否为回文结构（注意：面试时需要考量空间复杂度）

#include "iostream"
#include "stack"

using namespace std;

//class Node
struct Node
{
    int value;
    struct Node* next;
    Node(int val):value(val),next(nullptr){}
};


/*
 bool isPalindrome1(Node head){
     stack<Node> stack;
     Node cur=head;
     while(cur!=NULL){
        stack.push(cur);
        cur=cur.next;
     }
     while(head!=NULL){
        if(head.value!=stack.pop().value){
            return false;
        }
        head = head->next;
     }
     return true;
}
 */
//需要n个额外空间   利用栈将链表全部倒进去
bool isPalindrome1(Node *head){
     stack<int> stack;
     Node* cur=head;
     while(cur!=NULL){
        stack.push(cur->value);
        cur=cur->next;
     }
     while(head!=NULL){
        if(head->value!=stack.top()){
            return false;
        }
        stack.pop();
        head = head->next;
     }
     return true;
}
//需要n/2额外空间   利用栈+双指针
bool isPalindrome2(Node* head){
    if(head==NULL||head->next==NULL){
        return true;
    }
    Node* right=head->next;  
    Node* cur=head;
    while(cur->next!=NULL && cur->next->next!=NULL){
        right=right->next;
        cur=cur->next->next;
    }
    //stack<Node> stack;
    stack<int> stack;
    //right当前位置指向链表右半部分的第一个位置（不含中间）
    while(right!=NULL){
        stack.push(right->value);
        right=right->next;
    }
    while(!stack.empty()){
        if(head->value!=stack.top()){
            return false;
        }
        stack.pop();
        head=head->next;
    }
    return true;

}

//需要运用快慢指针 空间复杂度O(1)
bool isPalindrome3(Node* head){
    if(head==NULL||head->next==NULL){
       return true;
    }
    Node* n1=head;
    Node* n2=head;
    while (n2->next!=NULL && n2->next->next!=NULL){
        n1=n1->next;
        n2=n2->next->next;
    }
    n2=n1->next;
    n1->next=NULL;
    Node* n3=NULL;
    //reverse the rightside
    while(n2!=NULL){
        n3=n2->next;     //n3->save next node
        n2->next=n1;     //next of right node convert
        n1=n2;          //n1 move
        n2=n3;          //n2 move
    }
    n3=n1;              //n3->save last node
    n2=head;            //n2->left first node
    bool res=true;
    while(n1!=NULL&&n2!=NULL){
        if(n1->value!=n2->value){
            res=false;
            break;
        }
        n1=n1->next;
        n2=n2->next;
    }
    n1=n3->next;
    n3->next=NULL;
    //recover list
    while(n1!=NULL){
        n2=n1->next;
        n1->next=n3;
        n3=n1;
        n1=n2;
    }
    return res;
}
//创建一个实例链表进行测试
int main(){
   Node* head=new Node(5);
   head->next=new Node(4);
   head->next->next = new Node(5);
   head->next->next->next = new Node(7);
   head->next->next->next->next = new Node(3);
   head->next->next->next->next->next = new Node(4);
   head->next->next->next->next->next->next = new Node(5);
   bool x=isPalindrome1(head);
   bool y=isPalindrome2(head);
   bool z=isPalindrome3(head);
   //boolalpha用于将布尔类型按照true/false输出，endl表示换行。
   std::cout<<std::boolalpha<<x<<std::endl;
   std::cout<<y<<std::endl;
   std::cout<<z<<std::endl;
   return 0;
}