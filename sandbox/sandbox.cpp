#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>
#include <algorithm>  
#include <unordered_set>
#include <set>

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

set<vector<int>> subsets(vector<int>& nums){

    set<vector<int>> result;
   
    // base case
    if (nums.size() == 0){
        vector<int> empty;
        result.insert(empty);
        return result;
    }

    result.insert(nums);

    for(int i=0; i<nums.size();i++){
        vector<int> nums_copy;
        for(int j=0; j<nums.size(); j++){
            if(i !=j ) nums_copy.push_back(nums[j]);
        }
        cout << "vector: ";
        for (auto v:nums_copy){
            cout << v << ' ';
        }
        cout << endl;

        set<vector<int>> subs = subsets(nums_copy);

        for(auto s:subs){
            result.insert(s);
        }
    }
      
    return result;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    auto sets = subsets(nums);

    vector<vector<int>> result;

    for (auto s:sets){
        result.push_back(s);
    }

    return result;


}


        
int main(){

    int a = 0;

    cout << 1/a << endl;

    return 0;

    /*
    vector<vector<int>> result;

    vector<int> vec {1, 3, 4, 5};

    int N = vec.size();

    swap(vec[0], vec[N-1]);
    
    vec.pop_back();

    for(auto v:vec){
        cout << v << endl;


    }


    return 0;

    vector<int> empty;

    result.push_back(empty);

    cout << result.size() << endl;
    return 0;
    */


    //vector<int> A {1, 2, 2};
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


