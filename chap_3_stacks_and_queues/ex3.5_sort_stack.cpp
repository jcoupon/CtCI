
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void sortStack(stack<int> &s){

    stack<int> sTmp;
    int tmp;

    while(!s.empty()){
        tmp = s.top();
        s.pop();
        while(!sTmp.empty() && tmp < sTmp.top()){
            s.push(sTmp.top());
            sTmp.pop();
        }
        sTmp.push(tmp);
    }

    while(!sTmp.empty()){
        s.push(sTmp.top());
        sTmp.pop();
    }


    return;
}


int main(){

    stack<int> s;

    for(auto v:{6,1,5,6,7,1,2,8,0,5,2,9,1}) s.push(v);
    sortStack(s);

    while(!s.empty()){
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

