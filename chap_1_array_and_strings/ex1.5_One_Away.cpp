#include <iostream>

using namespace std;

bool isOneAway(const string &a, const string &b){

    if(a == b)
        return true;

    if(a.size() < b.size())
        return isOneAway(b, a);

    // assume a is larger or equal;
    int sizeDiff = a.size() - b.size();

    if(sizeDiff > 1)
        return false;

    bool edited = false;
    for(int i=0;i<b.size();++i){
        if(a[i] != b[i] && sizeDiff == 0){
            if(edited) return false;
            edited = true;
        }else if(a[i] != b[i] && sizeDiff > 0){
            return a.substr(i+1) == b.substr(i);
        }
    }

    return true;
}


int main(){

    cout << isOneAway("pale", "ple") << endl;
    cout << isOneAway("pale", "pales") << endl;
    cout << isOneAway("pale", "bale") << endl;
    cout << isOneAway("pale", "bake") << endl;
    cout << isOneAway("pald", "ple") << endl;

    return EXIT_SUCCESS;
}