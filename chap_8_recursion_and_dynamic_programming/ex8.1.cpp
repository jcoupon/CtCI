/*
Done well:
    - solved in 20 mn
    - first brute force, then with memoization
    - space and time complexity correct

To improve:
    - again the hand solution was not fully correct(missed some paths for 4)
    - used 1 hint but that's OK
    - thought about memoization after running it (should have used time complexity
    info)

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_ways(int n, int r, std::vector<int> * memo){ 
   
    int result;

    if (r<0) return 0;
    if (r == 0) return 1;

    if ((*memo)[r] == 0){
        (*memo)[r] = find_ways(1, r-1, memo)
            + find_ways(2, r-2, memo)
            + find_ways(3, r-3, memo);
    }

    result = (*memo)[r];

    return result;
}

int main(){

    int N = 20;
    
    // 3 -> 4
    // 4 -> 7
    // 20 -> 121415
    // 40 -> overflow...
    
    std::vector<int> memo(N, 0);

    std::cout << find_ways(0, N, &memo) << endl;

    return 0;
}

