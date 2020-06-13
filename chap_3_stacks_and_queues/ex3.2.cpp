/*
Done well:

To improve:

*/

#include <iostream>

using namespace std;


class Node{
    public:
        int data;
        Node *previous;
        int min;
};

class Stack{
    public:
        // constructor
        Stack();
        
        // pointer to top
        Node *ptop;
        int min_value;
        int N;

        // functions
        int top();
        void push(int);
        void pop();
        int min();    
};

Stack::Stack(){
    ptop = nullptr;
    N = 0;
}

void Stack::push(int d){

    Node *n = new Node();
    n->data = d;
    n->previous = ptop;

    if(N==0 || d < n->previous->min){
        n->min = d;
    }else{
        n->min = n->previous->min;
    }

    ptop = n;
    
    N++;
}

int Stack::top(){

    return ptop->data;
}

void Stack::pop(){

    Node *n = ptop;

    ptop = ptop->previous;
    delete n;

    N--;
}

int Stack::min(){
    return ptop->min;
}


int main(){

    Stack s;

    s.push(3);
    s.push(10);
    s.push(1);
    s.push(6);
    s.push(2);
    s.push(10);

    // 6
    std::cout << s.N << endl;

    // 10
    std::cout << s.top() << endl;

    s.pop();
    // 2
    std::cout << s.top() << endl;

    // 1
    std::cout << s.min() << endl;
    s.pop();
    s.pop();
    s.pop();
  
    // 3
    std::cout << s.min() << endl;


    return 0;
}


