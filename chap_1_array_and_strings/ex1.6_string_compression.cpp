#include<iostream>
#include<string>

std::string encode(const std::string &s){

    if(s.size() <= 1)
        return s;

    char prev = s[0];
    int count = 1;
    std::string result = "";
    for(int i=1;i<s.size();i++){
        if(s[i] != prev){
            result += prev+std::to_string(count);
            count = 1;
        }
        else{
            ++count;
        }
        prev = s[i];
    }
    result += prev+std::to_string(count);

    if(result.size() < s.size()){
        return result;
    }
    else{
        return s;
    }
}

int main(){

    std::string aabcccccaaa;
    std::cout << encode("aabcccccccccccccccccccgggggggggggggaaaccaaa") << std::endl;
    std::cout << encode("aabcccccaaa") << std::endl;
    std::cout << encode("abc") << std::endl;
    std::cout << encode("") << std::endl;
    std::cout << encode("h") << std::endl;

    return EXIT_SUCCESS;
}