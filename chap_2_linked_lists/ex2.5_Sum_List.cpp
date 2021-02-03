#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node ():  data(0), next(nullptr) {}
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

Node *buildList(const vector<int> &vec){
  
  Node *dummy = new Node();
  Node *runner = dummy;
  for(auto v:vec){
      Node *node = new Node(v);
      runner->next = node;
      runner = node;
  }

  return dummy->next;
}

Node* getSum(Node *a,  Node *b){

  Node *dummy = new Node();

  Node *runner = dummy;

  int carry = 0;
  
  while(a || b || carry){

    int s = carry;
    if(a){
      s += a->data;
      a = a->next;
    }
    if(b){
      s += b->data;
      b = b->next;
    }
    
    carry = s/10;
    runner->next = new Node(s%10);

    runner = runner->next;
  }

  return dummy->next;  
}

int main(){

  Node *a, *b;

  a = buildList({7, 1, 6});
  b = buildList({5, 9, 2});

  // 2 -> 1 -> 9
  printList(getSum(a, b));

  a = buildList({1});
  b = buildList({9, 9, 9});

  // 0 0 0 1
  printList(getSum(a, b));

  a = buildList({});
  b = buildList({9, 9, 9});

  // 9 -> 9 -> 9
  printList(getSum(a, b));

  a = buildList({1,5,3,7,8,9,1,2,4,7,5,4,3,3});
  b = buildList({1,5,3,7,8,9,1,2,4,7,5,4,3,3});

  // long ...
  printList(getSum(a, b));


  return EXIT_SUCCESS;
}