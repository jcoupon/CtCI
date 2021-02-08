#include <iostream>
#include <string>

using namespace std;

string toBinary(int n){

    if (n == 0)
        return "0";

    string result = "";
    while(n > 0){
        result += to_string(n%2);
        n = n/2;
    }
    for(int i=result.size(); i<16; ++i){
        result += '0';
    }

    std::reverse(result.begin(), result.end());

    return result;
}

pair<string, string> findNextPrev(string num){

    pair<string, string> result = {"no next", "no prev"};
    for(int i=num.size()-1; i>0; --i){
        if(num[i] == '1' && num[i-1] == '0'){
            result.first = num;
            swap(result.first[i], result.first[i-1]);
            break;
        }
    }

    for(int i=num.size()-2; i>=0; --i){
        if(num[i] == '1' && num[i+1] == '0'){
            result.second = num;
            swap(result.second[i], result.second[i+1]);
            break;
        }
    }

    return result;
}

int main(){

    std::cout << toBinary(pow(2,15)) << std::endl;

    pair<string, string> result;

    // 0000000001111110, 0000000001111011
    result = findNextPrev(toBinary(125));
    std::cout << result.first << ' ' << result.second << std::endl;

    // 0000000000000010, no prev
    result = findNextPrev(toBinary(1));
    std::cout << result.first << ' ' << result.second << std::endl;

    // no next, no prev
    result = findNextPrev(toBinary(0));
    std::cout << result.first << ' ' << result.second << std::endl;

    // no next, 0100000000000000
    result = findNextPrev(toBinary(pow(2, 15)));
    std::cout << result.first << ' ' << result.second << std::endl;

    // no next, 0100000000000000
    result = findNextPrev(toBinary(13948));
    std::cout << toBinary(13948) << std::endl;
    std::cout << result.first << ' ' << result.second << std::endl;

    return EXIT_SUCCESS;
}