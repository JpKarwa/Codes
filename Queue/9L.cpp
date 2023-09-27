// LEETCODE 239 -> Sliding window maximum

#include<iostream>
#include<deque>
#include<vector>
using namespace std;


vector<int> maxSlidingWindow(vector<int> &nums,int k){
    if(k==1) return nums;
    deque<int> dq;  // monotonice decreasing(index)
    vector<int> ans;  // window ka end hamesha >=k-1 pe hoga
    for(int i=0;i<nums.size();i++){
        while(dq.size()>0 && nums[i]>nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        int start=i-k+1;
        while(dq.front()<start) dq.pop_front(); 
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> v=maxSlidingWindow(nums,k);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};*/