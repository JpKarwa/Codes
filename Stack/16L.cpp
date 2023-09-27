// LEETCODE 503 -> Next Greater Element II

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElementCircular(vector<int> &nums){
    int n=nums.size();
    // creating a new array of double size
    vector<int> temp(2*n,0);
    // filling it with same value of nums in continuous manner
    for(int i=0;i<2*n;i++){
        temp[i]=nums[i%n];
    }
    // creating next smaller element array of temp
    vector<int> nge(2*n,-1);
    stack<int> s;
    s.push(temp[2*n-1]);
    for(int i=2*n-2;i>=0;i--){
        while(s.size()>0 && s.top()<=temp[i]) s.pop();
        if(s.size()!=0) nge[i]=s.top();
        s.push(temp[i]);
    }
    // creating final answer array for nums
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        ans[i]=nge[i];
    }
    return ans;
}

int main(){
    vector<int> nums={1,2,3,4,3};
    vector<int> ans=nextGreaterElementCircular(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}