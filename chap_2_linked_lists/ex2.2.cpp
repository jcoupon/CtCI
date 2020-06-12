#include <iostream>

/*
Done well:
    - working solution but again one step off
To improve:
    - test was not correct, spend more time on it
*/

using namespace std;

class Node{

    public:
        Node(int);
        int data;
        Node *next;

};

Node::Node(int d){
    data = d;
    next = nullptr;
}

void print_list(Node *root){
    Node *runner = root;
    while(runner){

        std::cout << runner->data;
        if(runner->next){
            std::cout << "->";
        }
        runner = runner->next;
    }
    std::cout << endl;

    return;
}

int get_kth(Node *root, int k){

    int n = 0 ;
    Node *node = root;
    Node *kth = nullptr;

    while(node->next){
        node = node->next;
        n++;
        if(n+1==k){
            kth = root;
        }
        else if(n+1>k){
            kth = kth->next;
        }
    }
    return kth->data;
}

int main(){

    // build list
    Node *root = new Node(6);
    int arr[7] {1,2,3,10,1,4,12};

    Node *runner = root;
    for (int a:arr){

        Node *node = new Node(a);
        runner->next = node;
        runner = node;

    }

    print_list(root);

    // 1
    std::cout << get_kth(root, 3) << endl;



    return 0;
}