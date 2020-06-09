#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function

    std::stringstream ss(str);
    std::vector<int> result;
    int n;
    char c;
    //string n;

    while(ss >> n){
        std::cout << n << endl;
        result.push_back(n);
        ss >> c;
    }

    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}