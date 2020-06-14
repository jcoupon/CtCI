/*
Done well:


To improve:



*/

#include <iostream>
#include <string>

using namespace std;

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

    /*
    o o o o
    o o x o
    o x o o

    - - - |
    o o x |
    o x o |
    */

    offLimits[1+r*2] = true;
    offLimits[2+r*1] = true;

    // printArr(offLimits);

    // true, rrrdd
    std::string path = "";
    std::cout << isPath(0, 0, r, c, &path, offLimits) <<  endl;
    std::cout << revert_string(path) << endl;

    /*
    o o o x
    o o x o
    o x o o

    no path
    */


    // false
    offLimits[0+r*3] = true;
    path = "";
    std::cout << isPath(0, 0, r, c, &path, offLimits) << endl;

    return 0;
}