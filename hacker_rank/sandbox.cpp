#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

string countAndSay(int n) {
    string s = "1";

    for (int j=1; j<n; j++){

        int count = 0;
        string result ="";

        for(int i=0; i<s.length(); i++){

            count++;
            if(i==s.length()-1){
                result += to_string(count) + s[i];
            }
            if(i<s.length()-1 && s[i] != s[i+1]){
                result += to_string(count) + s[i];
                count = 0;
            }
        }

        cout << result << endl;

        s = result;

    }

    return s;
}


string countAndSayR(int n) {
   
    if (n==1) return "1";
    else{

        string s = countAndSayR(n-1);

        int count = 0;
        string result ="";

        for(int i=0; i<s.length(); i++){

            count++;
            if(i==s.length()-1){
                result += to_string(count) + s[i];
            }
            if(i<s.length()-1 && s[i] != s[i+1]){
                result += to_string(count) + s[i];
                count = 0;
            }
        }
        return result;
    }
}



int main(){

    string result;

    result = countAndSayR(8);

    cout << result << endl;


    return 0;
}


