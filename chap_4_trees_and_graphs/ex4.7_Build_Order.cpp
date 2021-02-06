#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <exception>
#include <stdexcept>


using namespace std;

vector<char> getOrder(
    const vector<char> &projects, 
    const vector<vector<char>> &deps){

    int n = projects.size();

    vector<char> result;

    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> inDegree;

    for(auto dep:deps){
        graph[dep[0]].push_back(dep[1]);
        inDegree[dep[1]]++;
    }
    queue<char> q;
    for(int i=0; i<n; ++i){
        char p = projects[i];
        if(inDegree[p] == 0){
            q.push(p);
        }
    }
  
    while(!q.empty()){
        char p = q.front();
        q.pop();
        result.push_back(p);
        for(char nei:graph[p]){
            inDegree[nei]--;
            if(inDegree[nei] == 0){
                q.push(nei);
            }
        }
    }
        
    
    if(result.size() != n){
        throw runtime_error("No possible ordering");
    }

    return result;    
}

int main(){

    vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    // should throw exception
    //vector<vector<char>> deps = {{'b', 'f'}, {'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};
    vector<vector<char>> deps = {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};
    vector<char> projList = getOrder(projects, deps);
    for(auto proj:projList){
        std::cout << proj << ' ';
    }
    std::cout << std::endl;
   
    projects = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    deps = {{'d', 'g'}, {'f', 'c'}, {'f', 'b'}, {'f', 'a'}, {'c', 'a'}, {'b', 'a'}, {'a', 'e'}, {'b', 'e'}};
    projList = getOrder(projects, deps);
    
    for(auto proj:projList){
        std::cout << proj << ' ';
    }
    std::cout << std::endl;



    return EXIT_SUCCESS;
}



