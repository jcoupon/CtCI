#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class SetOfStacks{

public:
    int thres = 2;
    vector<stack<int>> stacks;
    int current_stack = -1;

    void create_stack();
    void push(int data);
    int pop();
    bool empty = true;

    int popAt(int index_stack);
};

void SetOfStacks::create_stack(){

    stack<int> s;
    stacks.push_back(s);
    current_stack++;

  return;
}

void SetOfStacks::push(int data){

  if(current_stack == -1){
    create_stack();
    empty = false;
  }
  else if(stacks[current_stack].size() == thres){
    create_stack();  
  }
  stacks[current_stack].push(data);

  return;
}

int SetOfStacks::pop(){

  if(empty) return -1;

  if(stacks[current_stack].empty()){
    current_stack--;
    if(current_stack == -1){
      empty = true;
        return -1;
    }
  }

  int data = stacks[current_stack].top();
    
  stacks[current_stack].pop();

  return data;
}

int SetOfStacks::popAt(int index_stack){

    // to discuss move around stacks or not??
    if(stacks[index_stack].empty()){
        for(int i=index_stack; i<stacks.size()-1; i++){
            stacks[i] = stacks[i+1];
        }
        return -1;
    }

    int data = stacks[index_stack].top();

    stacks[index_stack].pop();

    return data;

}


int main(){

    SetOfStacks sos;

    sos.push(1);
    sos.push(2);
    sos.push(3);
    sos.push(4);
    sos.push(5);


    for(int i=0; i<6; i++){
        cout << sos.pop() << endl;
    }

    sos.push(1);
    sos.push(2);
    sos.push(3);
    sos.push(4);
    sos.push(5);

    for(int i=0; i<6; i++){
        cout << sos.popAt(0) << endl;
    }
    return 0;
}