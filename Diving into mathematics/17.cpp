// MAXIMUM SUM SUBARRAY OF SIZE K

#include<iostream>
#include<vector>
using namespace std;

// brute force
// n-k is index having last subarray
int maximumSubarraySum(vector<int> &v,int k){
    int n=v.size();
    int maxSum=INT32_MIN;
    for(int i=0;i<n-k+1;i++){  // n-k+1 ops
        int sums=0;
        for(int j=i;j<i+k;j++){   // k times
            sums+=v[j]; 
        }
        maxSum=max(sums,maxSum);
    }
    // tc=> O(n*k-k*k)=> O(n*k)
    // k constant nhi h k toh very kr rha h
    return maxSum;
}

int maxSubarraySumOptimised(vector<int> &v,int k){
    int n=v.size();
    int sums=0;
    // starting ke k elements ka sum
    // first window ka sum
    for(int i=0;i<k;i++){  // k ops
        sums+=v[i];
    }
    int maxSum=sums;
    // int i=1;
    // int j=k;
    // while(j<n){
    //     sums+=v[j]-v[i-1];
    //     maxSum=max(maxSum,sums);
    //     i++;
    //     j++;
    // }
    for(int j=k;j<n;j++){    // n-k ops
        sums+=v[j]-v[j-k];
        maxSum=max(sums,maxSum);
    }
    // TC-> O(n-k+k)-> O(n)
    return maxSum;
}

int main(){
    vector<int> v={7,1,2,5,8,4,9,3,6};
    int k=3;
    cout<<maximumSubarraySum(v,k)<<endl;
    cout<<maxSubarraySumOptimised(v,k);
}