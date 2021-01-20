#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node (int data):  data(data), next(nullptr) {}

};

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

Node* part(Node *list, int value){

  Node* head = list;
  Node* tail = list;

  Node *runner = list;

  while(runner){
    Node *next = runner->next;

    if(runner->data < value){
      runner->next = head;
      head = runner;
    }
    else{
      tail->next = runner;
      tail = runner;
    }
    runner = next;
  }

  tail->next = nullptr;


  return head;
}


int main(){

    Node *head = new Node(0);
    vector<int> vec = {3, 5, 8, 5, 10, 2, 1};

    Node *runner = head;
    for(auto v:vec){
        Node *node = new Node(v);
        runner->next = node;
        runner = node;
    }

    printList(head->next);
    Node *result = part(head->next, 5);
    printList(result);

    return 0;
}