// Leetcode 204 -> Count Primes

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void fillSieve(vector<bool> &sieve){
    int n=sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++){
        for(int j=2*i;j<=n;j=j+i){
            sieve[j]=0;
        }
    }
}
int countPrimes(int n) {
    if(n<=2) return 0;
    int count=0;
    vector<bool> sieve(n+1,true);
    fillSieve(sieve);
    for(int i=2;i<=n-1;i++){
        if(sieve[i]) count++;
    }
    return count;
}

int main(){
    int n=100;
    cout<<countPrimes(n);
}