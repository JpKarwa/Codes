// LEETCODE 263-> Ugly Number

#include<iostream>
using namespace std;

bool uglyNumber(int n){
    if(n==0) return false;
    while(n%2==0) n/=2;
    while(n%3==0) n/=3;
    while(n%5==0) n/=5;
    return (n==1);
}

int main(){
    int n=6;
    cout<<uglyNumber(n);
}