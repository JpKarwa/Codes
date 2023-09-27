// LEETCODE 2614 -> Prime in Diagonal

#include<bits\stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int PrimeDiagonal(vector<vector<int>> &nums){
    int n=nums.size();
    int mx=0;
    for(int i=0;i<n;i++){
        if(isPrime(nums[i][i])){
            mx=max(mx,nums[i][i]);
        }
        if(isPrime(nums[i][n-i-1])){
            mx=max(mx,nums[i][n-i-1]);
        }
    }
    return mx;
}
// O(n root(n))
int main(){
    vector<vector<int>> nums={{1,2,3},{5,6,7},{9,10,11}};
    cout<<PrimeDiagonal(nums);
}