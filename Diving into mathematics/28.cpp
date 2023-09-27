// Given an integer n find the maximum power of two that is smaller than n

// 24 -> 11000
// msb lo uske aake sbko 0 krdo
// 10000->16

#include<iostream>
using namespace std;

int maximumTwoPower(int n){
    int temp=0;
    while(n>0){
        temp=n;
        n=n&(n-1);
    }
    return temp;
    // agar badi nikalni h se toh *2 krdo
}

int maximumTwoPower1(int n){
    n=n | (n>>1);
    n=n | (n>>2);
    n=n | (n>>4);
    n=n | (n>>8);
    n=n | (n>>16);
    return (n+1)>>1;
}

int main(){
    cout<<maximumTwoPower(24)<<" "<<maximumTwoPower1(24);
}