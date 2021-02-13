/*
Done well:


To improve:
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class SearchGrid{

public:
    int n, m;
    unordered_map<int, pair<bool, vector<vector<int>>>> memo;

    vector<vector<int>> getPath(vector<vector<int>> &grid){

        if(grid.size() == 0)
            return {};

        n = grid.size();
        m = grid[0].size();
   
        auto path = helperGetPath(grid, 0, 0);

        reverse(path.second.begin(), path.second.end());

        if(path.first){
            return path.second;
        }
        else{
            throw runtime_error("Not path found");

        }


  }
  
   pair<bool, vector<vector<int>>> helperGetPath(vector<vector<int>> &grid, int i, int j){
   
    // off limits
    if(i < 0 || i>= n || j < 0 || j >= m || grid[i][j] == 1){
      return {false, {}};
    }
    
    // reached goal
    if(i == n-1 && j == m-1){
      return {true, {{i,j}}};
    }
    
    if(memo.find(j+m*i) != memo.end()){
      return memo[j+m*i];
    }
          
    // continue path
    auto down = helperGetPath(grid, i+1, j);
    auto right = helperGetPath(grid, i, j+1);

    pair<bool, vector<vector<int>>> result;

    if(down.first){
      result = down;
    }
    else{
      result = right;
    }
    
    result.second.push_back({i, j});
   
    memo[j+m*i] = result;
   
    return memo[j+m*i];
   
   }
  
  
  
};

int main(){


    vector<vector<int>> grid(3, vector<int>(4, 0));
    grid[2][1] = 1;
    grid[1][2] = 1;

    // should return path
    auto path = SearchGrid().getPath(grid);
    for(auto step:path){
        std::cout << step[0] << ' ' << step[1] << std::endl;
    }

    // should take < 2s
    vector<vector<int>> bigGrid(100, vector<int>(100, 0));
    SearchGrid().getPath(bigGrid);   

    // should throw error
    grid[0][2] = 1;
    SearchGrid().getPath(grid);
    
    return EXIT_SUCCESS;
}










/*

void printArr(bool *arr){
    std::cout << arr[1+3*2] << endl;

    return;
}

std::string revert_string(std::string str){

    std::string res; 

    for (int i; i < str.length(); i++){
        res.push_back(str[str.length()-1-i]);
    }

    return res;

}


bool isPath(int i, int j, int r, int c, std::string *path, bool *offLimits){

    if(i>=c) return false;
    if(j>=r) return false;
    if(offLimits[i+r*j]) return false;
    
    // reached goal
    if (i==c-1 && j==r-1) return true;

    // down move
    if (isPath(i, j+1, r, c, path, offLimits)){
        // std::cout << 'd';
        *path += 'd';
        return true;
    }

    // right move
    if (isPath(i+1, j, r, c, path, offLimits)){
        *path += 'r';
        return true;
    }

    // no valid path found
    return false;
} 


int main(){

    // rows
    int r = 3;

    // columns
    int c = 4;

    bool *offLimits;
    offLimits = new bool[r*c];

    for (int i=0; i<c; i++){
        for (int j=0; j<r; j++){
            offLimits[i+r*j] = false;
        }
    }

    //o o o o
    //o o x o
    //o x o o

    //- - - |
    //o o x |
    //o x o |
    

    offLimits[1+r*2] = true;
    offLimits[2+r*1] = true;

    // printArr(offLimits);

    // true, rrrdd
    std::string path = "";
    std::cout << isPath(0, 0, r, c, &path, offLimits) <<  endl;
    std::cout << revert_string(path) << endl;

    
    //o o o x
    //o o x o
    //o x o o

    //no path
    


    // false
    offLimits[0+r*3] = true;
    path = "";
    std::cout << isPath(0, 0, r, c, &path, offLimits) << endl;

    return 0;
}



*/