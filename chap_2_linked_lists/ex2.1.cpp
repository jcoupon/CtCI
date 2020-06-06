#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// node for linked list
// todo make tempate 
class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    public:
        LinkedList ();
        Node *head;
        void insert(int);
        void print_list();
        void print_list_recursive(Node*);
        void remove_dups();
};

LinkedList::LinkedList(){
    head = nullptr;
}

void LinkedList::insert(int data){

    Node * node;
    
    node = new Node();

    node->data = data;
    node->next = head;

    head = node;

}

void LinkedList::remove_dups(){
    
    std::unordered_set<int> s;

    Node *pnode = head;
    Node *pprevious = nullptr;
    Node *next;
    do{
        next = pnode->next;
        if(s.find(pnode->data) == s.end()){
            s.insert(pnode->data);
            pprevious = pnode;
        }
        else{
            pprevious->next = pnode->next;
            delete pnode;
        }
        pnode = next;
    }while(pnode);

}

void LinkedList::print_list(){

    Node *pnode = head;
    do{
        std::cout << pnode->data << endl;
        pnode = pnode->next;
    }while(pnode);

}

void LinkedList::print_list_recursive(Node *pnode=nullptr){
    
    if (!pnode) pnode = head;

    std::cout << pnode->data << endl;
    if (pnode->next){
        print_list_recursive(pnode->next);
    }
    return;

}

LinkedList create_list(){

    int n[6] {2, 3, 4, 2, 1, 3};
    LinkedList l;
    
    for (int e:n){
        l.insert(e);
    }

    return l;
}

int main(){

    LinkedList l = create_list();

    l.print_list();
    // l.print_list_recursive();
    std::cout << "Remove duplicates" << endl;

    l.remove_dups();
    l.print_list();

    return 0;

}

