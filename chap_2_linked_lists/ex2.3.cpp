#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node (int data):  data(data), next(nullptr) {}

};

void deleteNode(Node *head, Node *nodeToDelete){
  
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




int main(){

    Node *head = new Node(0);
    vector<int> vec = {1, 3, 5, 1, 6};

    Node *runner = head;
    for(auto v:vec){
        Node *node = new Node(v);
        runner->next = node;
        runner = node;
    }


    return 0;
}