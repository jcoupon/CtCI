#include<iostream>
#include<string>

using namespace std;

void reverse(char* str){

  char tmp;
  int N=0;
  
  while(str[N] != '\0'){
    N++;
  }
  for(int i=0; i<N/2; i++){
    tmp = str[i];
    str[i] = str[N-1-i];
    str[N-1-i] = tmp;
  }

  return;
}

int main(){

    //char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    //char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str[] = "hello my name is Jean";

    cout << str << endl;
    reverse(str);
    cout << str << endl;


    return 0;
}

