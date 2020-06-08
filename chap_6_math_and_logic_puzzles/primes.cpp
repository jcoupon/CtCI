/*
    This is a different implementation from the book.

    Instead of multiplying by the prime I do a modulo operation
    which might not be allowed

    To implement again !!

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void check_div(int n, int j, vector<bool> *isPrime, vector<int> *num){

    for (int i=j; i<num->size(); i++){
        if ((*num)[i]%n == 0) (*isPrime)[i] = false;
    }
    
    return;
}

std::vector<int> find_primes(int n_max){

    // we exclude 0 and 1 but keep n_max
    int size = n_max - 1;
    std::vector<int> num(size);
    std::vector<bool> isPrime(size, true);
    
    //fill in numbers
    for (int i=0; i<size; i++){
        num[i] = i+2;
    }
    // 2
    isPrime[0] = true;
    for (int i=0; i<size; i++){
        if(isPrime[i]) check_div(num[i], i+1, &isPrime, &num);
    }

    // result = list of primes
    std::vector<int> primes;
    for (int i=0; i<size; i++){
        if(isPrime[i]) primes.push_back(num[i]);
    }

    return primes;
}


int main(){

    std::vector<int> primes = find_primes(100);

    for (int i; i<primes.size();i++){
        std::cout << primes[i] << endl;
    }

    return 0;
}

