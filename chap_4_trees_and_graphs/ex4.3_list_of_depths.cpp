
#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
};

class ListNode{
    public:
        int data;
        ListNode* next;
        void add_element(int);
        ListNode(int x) : data(x), next(nullptr) {}

};

void ListNode::add_element(int data){

    ListNode *n = this;

    while(n->next){
        n = n->next;
    }
    ListNode * node = new ListNode(data);
    n->next = node;

    return;
}


void build_tree(TreeNode *root){

    root->data = 2;

    // left
    TreeNode *left = new TreeNode();
    left->data = 5;
    root->left = left;
    
    // right
    TreeNode *right = new TreeNode();
    right->data = 6;
    root->right = right;

    return;
}

void traverseTree(TreeNode *node, int depth, vector<ListNode *> &lists){

    if(node == nullptr){
        return;
    }

    if (lists.size() < depth){
        ListNode *head = new ListNode(node->data);
        lists.push_back(head);
    }
    else{
        lists[depth-1]->add_element(node->data);
    }

    traverseTree(node->left, depth+1, lists);
    traverseTree(node->right, depth+1, lists);

}
vector<ListNode *> listOfDepths(TreeNode *root){

    vector<ListNode *> lists;

    traverseTree(root, 1, lists);

    return lists;
} 

void printList(ListNode *head){

    ListNode *runner = head;

    while(runner){
        cout << runner->data;
        if(runner->next){
            cout << "->";
        }
        runner = runner->next;
    }
    cout << endl;


    return;
}



int main(){

    TreeNode *head = new TreeNode();

    build_tree(head);

    vector<ListNode *> lists = listOfDepths(head);

    cout << "---" << endl;


    printList(lists[0]);
    printList(lists[1]);

    // result 
    // [2]
    // [5, 6]
    /*
    int arr [] = {2,4,5,10,12,13,14,15,20};
    ListNode *linked_list = new ListNode(2);
    cout << linked_list->data << endl;

    for(int i=1; i < 9;i++){
        linked_list->add_element(arr[i]);
    }

    printList(linked_list);
    */

    return 0;
}

