#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node (int data):  data(data), next(nullptr) {}

};

void deleteNodeWithHead(Node *head, Node *nodeToDelete){
  
  Node *runner = head;

  while(runner){
  
    if(runner->next == nodeToDelete){
      runner->next = runner->next->next;
      delete runner->next;
      return;
    }
    else{
      runner = runner->next;
    }
  }

  return;
}


void deleteNode(Node *nodeToDelete){
    
    Node *next = nodeToDelete->next;

    nodeToDelete->data = next->data;
    nodeToDelete->next = next->next;

  return;
}



void printList(Node *head){

    Node *runner = head;

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

    Node *head = new Node(0);
    vector<int> vec = {1, 3, 5, 1, 6};

    Node *nodeToDelete;

    Node *runner = head;
    for(auto v:vec){
        Node *node = new Node(v);
        runner->next = node;
        runner = node;
        if(v==3){ nodeToDelete = node;}
    }

    printList(head);
    deleteNodeWithHead(head, nodeToDelete);
    printList(head);


    runner = head;
    for(auto v:vec){
        Node *node = new Node(v);
        runner->next = node;
        runner = node;
        if(v==3){ nodeToDelete = node;}
    }

    printList(head);
    deleteNode(nodeToDelete);
    printList(head);

    return 0;
}