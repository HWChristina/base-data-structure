//当前节点的后继节点（中序遍历二叉树后x后面的节点称为后继节点）
#include "iostream"
#include "algorithm"

struct Node{
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val):value(val){}
};


Node* getSuccessorNode(Node* node){
    //讨论空的情况
    if(node==NULL){
        return NULL;
    }
    //寻找后继节点的两种情形
    //1.若右子树不为空，则返回右子树的最左节点
    if(node->right!=NULL){
        return getLeftMost(node->right);
    }
    //2.右子树为空，父节点不为空且自己不是父节点的左孩子，就继续向上找
    else{
        Node* parent = node->parent;
        while(parent!=NULL&&parent->left!=node){
            node =parent;
            parent = node->parent;
        }
        return parent;
    }

}
//其实带入的是主函数node里的右孩子节点
Node* getLeftMost(Node* node){
    if (node==NULL){
        return node;
    }
    while(node->left!=NULL){
        node = node->left;
    }
    return node;
}