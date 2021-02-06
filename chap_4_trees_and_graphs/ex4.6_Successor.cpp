/*

*/


#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node *parent;
    Node (int val): val(val) {} 

};

int findLeftMost(Node *node){

    if(!node){
        return -1;
    }

    while(node->left)
        node = node->left;

    return node->val;
}

int findNext(Node *node){
    
    if(node->right)
        return findLeftMost(node->right);
 
    Node *parent = node->parent;    
    while(parent != nullptr && parent->left != node){
        node = parent;
        parent = parent->parent;
    }

    if(parent){
        return parent->val;
    }
    else{
        return -1;
    }

 }




int main(){

    Node *root = new Node(5);
    root->parent = nullptr;

    Node *node = root;

    node->left = new Node(3);
    node->left->parent = node;
    node->right = new Node(6);
    node->right->parent = node;

    node = node->left;
    node->left = new Node(1);
    node->left->parent = node;
    node->right = new Node(4);
    node->right->parent = node;

    // -1
    cout << findNext(root->right) << endl;

    // 6
    cout << findNext(root) << endl;
    
    // 3
    cout << findNext(root->left->left) << endl;

    // 5
    cout << findNext(root->left->right) << endl;

    return 0;
}



