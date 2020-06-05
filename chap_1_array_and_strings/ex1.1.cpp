#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool check_unique(std::string str){

    std::unordered_set<char> char_set;
    for (char c:str){
        char_set.insert(c);
    }
    return char_set.size() == str.length();
}

bool check_unique_sort(std::string str){

    sort(str.begin(), str.end());

    int previous = -1;
    for (char c:str){
        if (previous >= 0){
            if (str[previous] == c) return false;
        }

        previous++;

    }

    return true;
}


int main(){

    // should return true
    std::cout << check_unique_sort("train") << endl;

    // should return false
    std::cout << check_unique_sort("room") << endl;

    // should return true
    std::cout << check_unique_sort("") << endl;

    return 0;

}

