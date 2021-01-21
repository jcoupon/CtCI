#include <iostream>
#include <stack>

class MyQueue{
private:
    std::stack<int> L;
    std::stack<int> R;

public:
    // MyQueue(): default;

    void push(int val){
        L.push(val);
    }

    int front(){
        if(R.empty()){
            while(!L.empty()){
                R.push(L.top());
                L.pop();
            }

        }
        if(R.empty())
            return -1;
        
        int result = R.top();
        R.pop();
        return result;
    }

    bool isEmpty(){
        return R.empty() && L.empty();
    }


};


int main(){

    MyQueue q;

    for(int i=0; i<5; ++i) q.push(i+1);

    q.front();
    q.push(6);
    q.front();
    q.push(7);

    while(!q.isEmpty()){
        std::cout << q.front() << std::endl;
    }
    
    return 0;



}