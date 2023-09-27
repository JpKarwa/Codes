// LEETCODE 507 -> Perfect Number

#include<bits\stdc++.h>
using namespace std;

bool checkPerfectNumber1(int n){
    int sumOfFactors=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0 && i!=n){
            sumOfFactors+=i;
            if(i!=sqrt(n) && n/i!=n) sumOfFactors+=n/i;
        }
    }
    return sumOfFactors==n;
}

bool checkPerfectNumber2(int n){
    int sumOfFactors=0;
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0) sumOfFactors+=i;
    }
    for(int i=sqrt(n);i>=1;i--){
        if(n%i==0) sumOfFactors+=n/i;
    }
    sumOfFactors-=n;
    return sumOfFactors==n;
}

int main(){
    int n=28;
    cout<<checkPerfectNumber1(n)<<endl;
    cout<<checkPerfectNumber2(n)<<endl;
}