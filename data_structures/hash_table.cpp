#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

class TagClass{

    public:
        std::unordered_map<std::string, std::string> attributes;
        std::map<std::string, TagClass *> children;

};


void split_str(std::string str, std::vector<std::string> *substrs, char delim=' '){

    std::size_t start=0, end;
    std::string substr;

    for (;;){
        end = str.find(delim, start);
        // cout << start << endl;
        // cout << end << endl;

        if (end == std::string::npos){
            substr = str.substr(start);
        }
        else{
            substr = str.substr(start, end-start);
        }
        
        substrs->push_back(substr);

        start = end+1;
        
        if (end == std::string::npos) break;

    }

    // cout << (*str).find(delim) << std::string::npos << endl;
    // cout << *str << endl;




}

int main(){

    std::string str;
    TagClass tag;

    str = "<this is a=sentence>";

    std::vector<std::string> substrs;

    str = str.substr(1, str.size()-2);

    split_str(str, &substrs, '=');

    tag.attributes[substrs[0]] = substrs[1];

    cout << substrs[0] << endl;

    for (string elem:substrs){
        cout << elem << endl;
    }


    return 0;

}


