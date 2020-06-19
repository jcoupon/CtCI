/* group anagrams
    done well:
        - got the idea to first sort the strings right
        - also thought about using a hash table, but first had the idea
        to swap the values to append the anagrams after the first occurence,
        but it doesn't work if there are more than two


    to improve:
        - wrongly tried to find a too optimum solution, go ahead with 
        a first solution

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

std::string sort_str(const std::string &in){

    std::string out = in;        
    std::sort(out.begin(), out.end());

    return out;
}


int main(){

    // init array of strings
    std::vector<std::string> strings;

    strings.push_back("race");
    strings.push_back("train");
    strings.push_back("silent");
    strings.push_back("care");
    strings.push_back("listen");
    strings.push_back("acre");

    std::unordered_map<string, vector<string>> sorted_dict;
    for (std::string str:strings){
        std::string sorted_str = sort_str(str);
        sorted_dict[sorted_str].push_back(str);
    }

    for (auto x : sorted_dict){
        for (auto s:x.second){
            cout << s << endl;
        }
    }

    return 0;
}