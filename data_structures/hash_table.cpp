#include <iostream>
#include <string>
using namespace std;

int y;

void modify_y(){

    y = 10;

    return;
}

int main(){

    cout << "Type a city" << endl;

    // char answer [20];

    string answer;

    // getline(cin, answer);
    answer = "Geneve";

    string other_variable = "this";

    string *p;

    p = &answer;

    // cin >> answer;

    //string answer_string;
    //answer_string = answer;

    //cout << answer_string << endl;
    //cout << answer_string.c_str() << endl;

    cout << *p << p << endl;



    return 0;

}


