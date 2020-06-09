/*
Done well:
    - rapidly framed the problem but failed to solve the last 
    item issue
To improve:
    - algorithm
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> shift_array(vector<int> arr, int size){

    int size_arr = arr.size() - size;
    int tmp;

    for (int i=0; i<size_arr; i++){
        tmp = arr[size-1-i];
        arr[size-1-i] = arr[arr.size()-1-i];
        arr[arr.size()-1-i] = tmp;
    }

    return arr;
}


std::vector<int> merge_two_noshift(std::vector<int> A, std::vector<int> B){

    std::vector<int> res(A.size()+B.size(), 0);
    int i=0, j=0;

    for (auto it=res.begin(); it!=res.end(); it++){        
        if(i==A.size()){
            *it = B[j];
            break;
        }
        if(j==B.size()){
            *it = A[i];
            break;
        }

        if (A[i] < B[j]){
            *it = A[i];
            i++;
        }
        else{
            *it = B[j];
            j++;
        }
    }

    return res;
}


vector<int> merge_two(vector<int> A, vector<int> B){

    A = shift_array(A, B.size());

    // return A;

    int i=0; 
    int ia=B.size();
    int ib=0;

    while (i<A.size()){
        
       if(ia==A.size()){
            A[i] = B[ib];
            break;
        }
        if(ib==B.size()){
            A[i] = A[ia];
            break;
        }

        if(A[ia] < B[ib]){
            A[i] = A[ia];
            ia++;
        }else{
            A[i] = B[ib];
            ib++;
        }
        i++;
    }


    for (auto it = A.begin(); it != A.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << endl;

    return A;
}

int main(){

    std::vector<int> A {2,4,8,10, 0, 0, 0, 0};
    std::vector<int> B {0,1,6,12};

    A = merge_two(A, B);

    for (auto it = A.begin(); it != A.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << endl;

    return 0;
}

