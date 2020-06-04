#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

class TagClass{

    public:
        std::string name;
        std::unordered_map<std::string, std::string> attributes;
        std::unordered_map<std::string, TagClass *> children;
        TagClass * parent;
        
};


std::vector<std::string> split_str(std::string str, std::string delim=" "){

    std::size_t start=0, end;
    std::string token;
    std::vector<std::string> tokens;

    for (;;){
        end = str.find(delim, start);
        if (end == std::string::npos){
            token = str.substr(start);
        }
        else{
            token = str.substr(start, end-start);
        }
        
        tokens.push_back(token);

        start = end+1;
        
        if (end == std::string::npos) break;
    }

    return tokens;
}

TagClass parseTag(std::string line){
    /*
    Parse line and return tag object
    */

    TagClass tag;

    // remove < and >
    line = line.substr(1, line.size()-2);

    // split string
    std:vector<std::string> tokens = split_str(line);

    // tag name
    // cout << tokens[0] << endl;
    tag.name = tokens[0];

    // tag attributes
    for(int j=1; j<tokens.size(); j+=3){
        tag.attributes[tokens[j]] = tokens[j+2].substr(1,tokens[j+2].size()-2);
    }

    return tag;
}

int main(){

    // for tests, mimic standard input stream
    std::string str_in =
"4 3\n"
"<tag1 value = \"HelloWorld\" value2 = \"byeWorld\">\n"
"<tag2 name = \"Name1\">\n"
"<tag3 name = \"Name1\">\n"
"</tag3>\n"
"</tag2>\n"
"</tag1>\n"
"tag1.tag2~name\n"
"tag1~name\n"
"tag1~value";
 
    std::istringstream stream(str_in);
 
    int N, Q;
    std::string line;

    stream >> N >> Q;
 
    // go to the next line
    std::getline(stream, line);

    std::cout << N << ' ' << Q <<  endl;

    TagClass *root = new TagClass();        
    root->parent = nullptr;
    root->name = "root";

    TagClass *current = root;

    //cout << current->name << endl;

    for (int i=0; i<N; i++){

        // read line
        std::getline(stream, line);

        // if closing tag climb up
        if (line.at(1) == '/'){
            current = current->parent;
            continue;
        }

        // parse tag
        TagClass *tag = new TagClass();        
        *tag = parseTag(line);

        // record parent pointer
        tag->parent = current;

        // record child pointer in parent 
        current->children[tag->name] = tag;

        /*
        if (tag->attributes.find("value") != tag->attributes.end()){
            cout << tag->attributes["value"] << endl;
        }
        else{
            std::cout << "Not Found!" << endl;
        }
        */

       
        current = tag;

        //cout << tag << endl;


        //int a;
        //cout << &a << endl;

    }

    for (int i=0; i<Q; i++){
        // read line
        std::getline(stream, line);

        std::cout << line << endl;

        std::vector<string> tags = split_str(line, ".");

        current = root;
        for (std::string tag:tags){
            std::cout << tag << endl;

        }


    }



    std::cout << root->children["tag1"]->attributes["value"] << endl;

    return 0;
}


