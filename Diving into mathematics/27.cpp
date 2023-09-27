// Find the number of set bits for any integer n
// set bits are the no. of 1's in binary form of number n

// x aur x-1 pe visualize kre agar binary me toh ek cheez hoti h ki
// ek region exactly same hota aur dusra exactly flipped
// x ki jo last set bit h vha se lekar end tk x-1 me sb kuch flipped hoga

#include<bits/stdc++.h>
using namespace std;

int countSetBits1(int n){
    return __builtin_popcount(n);
}

int countSetBits2(int n){
    // brian kerninghas algo
    int setBits=0;
    while(n>0){
        // ye last set bit ko hata dega har iteration me
        // flipped region me ek hi set bits
        // toh jitna baar ye loop chalega utni hi set bits h
        n=n&(n-1);
        setBits++;
    }
    return setBits;
}

int main(){
    cout<<countSetBits1(13)<<" "<<countSetBits2(13);
}