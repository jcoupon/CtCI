#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

int main(){



    int result;
    
    try{
        result = stoi("333456168168168168168684684684684");
    }
    catch(...){

        result = 0;
    }

    cout << result << endl;


    return 0;
}


