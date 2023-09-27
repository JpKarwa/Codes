// LEETCODE 650 - 2 Keys Keyboard

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int highestFactor(int n){
    int hf=1;
    // n-1 se bhi start kr skte h
    for(int i=n/2;i>=2;i--){
        if(n%i==0) return i;
    }
    return 1;
}

int minSteps(int n){
    int minOps=0;
    while(n>1){               // O(log(n))
        if(isPrime(n)){       // O(sqrt(n))
            minOps+=n;
            break;
        }
        int hf=highestFactor(n); // O(sqrt(n))
        minOps+=(n/hf);
        n=hf;
    }
    return minOps;
}

// 128<-64<-32<-16<-4<-2<-1 => log(128)=> 7 ops 
// 130<-65<-13 => while 2 baar chala bs


int main(){
    int n=100;
    cout<<minSteps(n);
}

/*
class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }

    int highestFactor(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return n/i;
        }
        return 1;
    }

    int minSteps(int n) {
        int minOps=0;
        // n ko 1 bana rhe h
        // reverse khel rhe h
        while(n>1){
            if(isPrime(n)){
                minOps+=n;
                break;
            }
            int hF=highestFactor(n);
            minOps+=n/hF;
            n=hF;
        }
        return minOps;
    }
};
*/