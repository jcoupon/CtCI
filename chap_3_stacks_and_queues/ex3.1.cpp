/*
Done well:
    - came up with the right solution although looked at the hints
        to make sure it was the right way

To improve:
    - think about of the design: forgot to include stack argument in 
        helper functions in the begining
    - remember reserve function for vector
    - some minor syntax errors
    - the first solution was wrong (was jumping to the 2nd element at first), test!
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class ThreeStacks{

    std::vector<int> arr;

    public:
        // member
        int start[3];
        int end[3];
        int size;

        // constructor
        ThreeStacks(int);

        // functions
        void push(int, int);
        bool isEmpty(int);
        int top(int);
        void pop(int);

        void print_stack(int);
};

ThreeStacks::ThreeStacks(int N){
    size = N;

    // arr = new std::vector<int>(N);
    arr.reserve(N);

    start[0] = end[0] = 0;
    start[1] = end[1] = N/3;
    start[2] = end[2] = 2*N/3;
     
}

void ThreeStacks::push(int stack, int data){

    arr[end[stack]] = data;
    end[stack]++;
}

bool ThreeStacks::isEmpty(int stack){
    return start[stack] == end[stack];
}

int ThreeStacks::top(int stack){
    return arr[end[stack]-1];
}

void ThreeStacks::pop(int stack){
    end[stack]--;
}

void ThreeStacks::print_stack(int stack){

    for (int i = start[stack]; i<end[stack]; i++ ){
        std::cout << arr[i] << ' ';
    }
    std::cout << endl;

}

int main(){

    ThreeStacks * myStack = new ThreeStacks(100);

    for (int stack=0; stack <3; stack++){

        std::cout << "Is empty:" << myStack->isEmpty(stack) << endl;

        myStack->push(stack, 10);
        std::cout << "Is empty:" << myStack->isEmpty(stack) << endl;

        myStack->push(stack, 20);
        myStack->push(stack, 3);
        myStack->push(stack, 6);
        myStack->push(stack, 1);

        std::cout << myStack->top(stack) << endl;

        myStack->print_stack(stack);

        myStack->pop(stack);
        myStack->pop(stack);

        myStack->print_stack(stack);

    }

    return 0;
}

