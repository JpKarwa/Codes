// Given an integer number n flip all bits.

// all 1's ke sath xor krde toh hmara answer aajayega

#include<iostream>
using namespace std;

string decToBin1(int x){
    string s="";
    while(x>0){
        int rem=x%2;
        s=to_string(rem)+s;
        x=x/2;
    }
    return s;
}

int maximumTwoPower1(int n){
    n=n | (n>>1);
    n=n | (n>>2);
    n=n | (n>>4);
    n=n | (n>>8);
    n=n | (n>>16);
    return (n+1)>>1;
}

void flipBinary(int n){
    int maxp=maximumTwoPower1(n);
    int dble=maxp*2;
    int mask=dble-1;
    int ans=n^mask;
    cout<<decToBin1(ans);
}

int main(){
    flipBinary(8);
}

// 1 ko switch off krne ke liye xor lagana padega
// aur 0 ko switch on krne ke liye xor lagana padega