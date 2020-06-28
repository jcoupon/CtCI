#include <iostream>


using namespace std;

// simple solution, O(N) space
string URLify(string str){

  string res = "";
  for(int i=0 ; i<str.length(); i++){
  
    if(str[i] == ' '){
      res += "%20";
    }
    else{
      res += str[i];
    }  
  }

  return res;
}

// more complicated solution, in place

// with char array
void URLify_arr(char *str, int N){
   
  int N_spaces = 0;
  
  for(int i=0; i < N; i++){
    if(str[i] == ' ') N_spaces++;  
  }

  int end = N+N_spaces*2;
  for(int i=N-1; i>=0; i--){
    
    if(str[i] == ' '){
      end--;
      str[end] = '0';
      end--;
      str[end] = '2';
      end--;
      str[end] = '%';
    }
    else{
      end--;
      str[end] = str[i];
    }
  }

  return;

}

int main(){

    string str = "Mr John Smith";

    cout << URLify(str) << endl;

    char str2[] = "Mr John Smith    ";

    URLify_arr(str2, 13);

    cout << str2 << endl;

    return 0;

}