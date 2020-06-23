#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;


unordered_map<int, vector<int>>int_to_indices(vector<int>& vec){

  unordered_map<int, vector<int>> result;

  for(int i=0; i<vec.size(); i++){
    result[vec[i]].push_back(i); 
  }
  
  return result;
}

int main(){

    string result;


    cout << result << endl;


    return 0;
}


