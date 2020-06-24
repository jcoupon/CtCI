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


int maxUncrossedLines(vector<int>& A, vector<int>& B) {

    int M = A.size();
    int N = B.size();

    vector<vector<int>> memo(M, vector<int>(N, -1));
   
    // return CLS(A, B, A.size()-1, B.size()-1, memo);

    return CLS_DP(A, B);

}
  
  
    
        
int main(){

    vector<int> A {2, 5, 1, 2, 5};

    vector<int> B {10,5, 2, 1, 5, 2};

    cout << maxUncrossedLines(A, B) << endl;


    return 0;
}


