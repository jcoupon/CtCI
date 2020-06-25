#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>
#include <algorithm>  

using namespace std;

int CLS(vector<int>& A, vector<int>& B, int i, int j, vector<vector<int>> memo){


    if(i<0 || j<0) return 0;

    if (memo[i][j] != -1){
        return memo[i][j];
    }

    int result;

    if(A[i] == B[j]){
        result = 1+CLS(A, B, i-1, j-1, memo);
    }
    else{

        result = max(CLS(A, B, i-1, j, memo), CLS(A, B, i, j-1, memo));
    }

    memo[i][j] = result;

    return result;
}


int CLS_DP(vector<int>& A, vector<int>& B){

    int M = A.size();
    int N = B.size();

    vector<vector<int>> DP(M+1, vector<int>(N+1, 0));

    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            if(A[i-1] == B[j-1]){
                DP[i][j] += 1+DP[i-1][j-1];
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    
    return DP[M][N];

}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>> result;
   
    // base case
    if (nums.size() == 0){  
        return result;
    }

    for(int i=0; i<nums.size();i++){
        vector<int> nums_copy = nums;
        nums_copy.erase(nums_copy.begin() + i);
        result = subsetsWithDup(nums_copy);
        result.push_back(nums);
    }
      
    return result;       
}


    
        
int main(){

    vector<int> A {1, 2, 2};

    auto sets = subsetsWithDup(A);


    for (auto s:sets){

        for (auto v:s){

            cout << v << ' ';

        }
        cout << endl;


    }

    return 0;
}


