// Calculate the number of bit flips to convert from one number to another

#include<iostream>
using namespace std;

int countSetBits1(int n){
    return __builtin_popcount(n);
}

int main(){
    int x=5;
    int y=11;
    cout<<countSetBits1(x^y);
}

// and krke no. of zeros