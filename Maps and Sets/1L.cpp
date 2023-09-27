// LEETCODE 2442 -> Count number of distinct integers after reverse operations

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int reverse(int n){
    int rev=0;
    while(n>0){
        int digit=n%10;
        rev=rev*10+digit;
        n=n/10;
    }
    return rev;
}
// Method 1
int countDistinctIntegers1(vector<int> &nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int rev=reverse(nums[i]);
        nums.push_back(rev);
    }
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    return s.size();
}
// Method 2
int countDistinctIntegers2(vector<int> &nums){
    int n=nums.size();
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        int rev=reverse(nums[i]);
        s.insert(nums[i]);
        s.insert(rev);
    }
    return s.size();
}

int main(){
    vector<int> nums={1,13,10,12,31};
    cout<<countDistinctIntegers1(nums)<<" ";
    cout<<countDistinctIntegers2(nums);
}