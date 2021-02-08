#include <iostream>
#include <string>

using namespace std;

string toBinary(int n){

    if (n == 0)
        return "0";

    string result = "";
    while(n > 0){
        result += to_string(n%2);
        n = n/2;
    }
    for(int i=result.size(); i<16; ++i){
        result += '0';
    }

    std::reverse(result.begin(), result.end());

    return result;
}


int getNext(int n){

  if(n==0 || n==INT_MAX)
    return -1;

  int c0 = 0;
  int c1 = 0;
  int tmp = n;
  
    while((tmp&1) == 0){
        ++c0;
        tmp >>= 1;
    }
    while((tmp&1) == 1) {
        ++c1;
        tmp >>= 1;
    }
    int p = c0+c1;

    if(c0+c1 == 31)
        return -1;

    n |= (1<<(p));
    n &= ~((1<<p)-1);
    n |= (1<<(c1-1))-1;

    return n;

}


int getPrevious(int n){

  if(n==0 || n==INT_MAX)
    return -1;

  int c0 = 0;
  int c1 = 0;
  int tmp = n;
  
    while((tmp&1) == 1){
        ++c1;
        tmp >>= 1;
    }
    while((tmp&1) == 0) {
        ++c0;
        tmp >>= 1;
    }
    if (tmp == 0) return -1;

    int p = c0+c1;

    n &= ((~0) << (p+1));
    int mask = (1<<(c1+1)) - 1;
    n |= mask << (c0-1);

    return n;
}


int main(){

    int n;

    n = 13948;
    std::cout << toBinary(n) << ' ' << toBinary(getNext(n)) << ' ' <<  getNext(n) << std::endl;

    n = INT_MAX-1;
    std::cout << toBinary(n) << ' ' << toBinary(getNext(n)) << ' ' <<  getNext(n) << std::endl;

    n = 10115;
    std::cout << toBinary(n) << ' ' << toBinary(getPrevious(n)) << ' ' <<  getPrevious(n) << std::endl;

    n = 0;
    std::cout << toBinary(n) << ' ' << toBinary(getPrevious(n)) << ' ' <<  getPrevious(n) << std::endl;

    n = INT_MAX-1;
    std::cout << toBinary(n) << ' ' << toBinary(getPrevious(n)) << ' ' <<  getPrevious(n) << std::endl;

    return EXIT_SUCCESS;
}