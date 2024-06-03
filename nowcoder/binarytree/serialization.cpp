//二叉树的序列化与反序列化
#include "iostream"
#include "queue"
#include "string"

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int val):value(val),left(nullptr),right(nullptr){}
};


//二叉树的前序序列化


string serialByPre(Node* node){
    if(node==NULL){
        return "#";
    }
    //string res = node->value+"_";
    //res +=serialByPre(node->left);
    //res +=serialByPre(node->right);
    return to_string(node->value) + "_" + serialByPre(node->left) + "_" + serialByPre(node->right);
    //return res;
}

//二叉树的前序序列反序列化
//左的方法无法运用到c++的代码当中，因为c++中没有分割字符串的方法需要自己写
/* Node *reconByPreString(String preStr){
    String[] values = preStr.split("_");
} */


//递归
Node* reconByPreOrder(queue<string>& queue){
    //队列元素：2 # # 3 4 # # 5 # #
    string tmp = queue.front();//取队列顶的元素
    queue.pop();               //弹出队列
    if("#"==tmp){
        return NULL;
    }
    //stoi函数：将n进制的字符串转化为十进制，使用时需要包含头文件string.
    Node* node = new Node(stoi(tmp));
    node->left = reconByPreOrder(queue);
    node->right = reconByPreOrder(queue);
    return node;
}
//主函数调用函数
//根据下划线给字符串做值的分割，再将每个值放进一个队列中，通过消费队列去建唯一的二叉树。
Node* reconByPreString(string preStr){
    if(0==preStr.length())
        return NULL;
    //建立string类型的队列
    queue<string> seq;
    while(0!=preStr.length()){
        //单独字符串第一个元素（原二叉树根节点）
        char tmp = preStr[0];
        preStr = preStr.substr(1);   //从preStr第1位开始到尾的字符串
        //如果遇到下划线，继续
        if('_'==tmp)
            continue;
        //将子节点不包括下划线插入ss字符串
        string ss(1,tmp);   //s从1位置开始，插入tmp字符串
        seq.push(ss);       //将ss压进栈seq
        //队列元素：2 # # 3 4 # # 5 # #
    }
        return reconByPreOrder(seq);
}
/* string preSerialize(Node* root){
    if(!root)
        return  "#";
    return to_string(root->val) + "," + preSerialize(root->left) + "," + preSerialize(root->right);

} */
int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    //序列化
    string ser = serialByPre(node1);
    cout<<ser<<endl;

    //反序列化
    Node* ret = reconByPreString(ser);
    cout<< serialByPre(ret);
    return 0;
    }
