#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


bool check_perm(string str1, string str2){

    if (str1.length() != str2.length() ) return false;

    std::unordered_map<char, int> char_num;

    for (char c:str1){
        if(char_num.find(c) == char_num.end()){
            // first encounter with c, set 1
            char_num[c] = 1;
        }
        else{
            // subsequent encounter with c, increment
            char_num[c]++;
        }
    }
    for (char c:str2){
        // c not found
        if(char_num.find(c) == char_num.end()){
            return false;
        }
        else{
            char_num[c]--;
            // ran out of c, delete it
            if(char_num[c] == 0){
                char_num.erase(c);
            }
        }
    }
    
    // the char set is empty str2 is a permutation of str1
    if (char_num.size() == 0) return true;

    // str1 has more character than str2
    return false;
}


int main(){

    string a = "ball";

    // true
    std::cout << check_perm(a, "abll") << endl;

    // false
    std::cout << check_perm(a, "abl") << endl;

    // false
    std::cout << check_perm(a, "clbl") << endl;

    // false
    std::cout << check_perm(a, "cl") << endl;

    return 0;
}