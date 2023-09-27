// LEETCODE 239 -> Slding window maximum

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums,int k){
    if(k==1) return nums;
    int n=nums.size();
    stack<int> s;
    s.push(n-1);
    vector<int> ngei(n,n);
    for(int i=n-2;i>=0;i--){
        while(s.size()>0 && nums[s.top()]<=nums[i]) s.pop();
        if(s.size()==0) ngei[i]=n;
        else ngei[i]=s.top();
        s.push(i);
    }
    vector<int> ans;
    int j=0;
    for(int i=0;i<n-k+1;i++){
        if(j<i) j=i;
        int mx=nums[j];
        while(j<i+k){
            mx=nums[j];
            if(ngei[j]>=i+k) break;
            j=ngei[j];
        }
        ans.push_back(mx);
    }
    return ans;
}

int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> ans=maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }    
}