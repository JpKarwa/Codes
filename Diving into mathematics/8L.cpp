// LEETCODE 2521 -> Distinct Prime Fatcors of product of array

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void fillSieve(vector<bool> &sieve){
    int n=sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++){
        if(sieve[i]==1){
            for(int j=2*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
    }
}

int distinctPrimeFactor(vector<int> &nums){
    int n=nums.size();
    int mx=-1;
    for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
    }

    vector<bool> sieve(mx+1,1);
    sieve[0]=0;
    sieve[1]=0;
    fillSieve(sieve);

    vector<int> primes;
    for(int i=0;i<mx+1;i++){
        if(sieve[i]==1) primes.push_back(i);
    }

    vector<bool> taken(primes.size(),0);
    for(int i=0;i<n;i++){
        int ele=nums[i];
        for(int j=0;j<primes.size();j++){
            if(primes[j]>ele) break;
            if(ele%primes[j]==0) taken[j]=1;
        }
    }

    int count=0;
    for(int i=0;i<taken.size();i++){
        if(taken[i]==1) count++;
    }

    return count;
}

int main(){
    vector<int> nums={2,4,3,7,10,6};
    cout<<distinctPrimeFactor(nums);
}