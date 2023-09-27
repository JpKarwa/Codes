// LEETCODE 496 -> Next Greater Element I

#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1,vector<int> &nums2){
    int m=nums1.size();
    int n=nums2.size();
    // find the next greater element array of nums2
    vector<int> nge(n,-1);
    stack<int> s;
    s.push(nums2[n-1]);
    for(int i=n-2;i>=0;i--){
        while(s.size()>0 && s.top()<=nums2[i]) s.pop();
        if(s.size()!=0) nge[i]=s.top();
        s.push(nums2[i]);
    } 
    // storing nextGreater of each element in map
    // key -> element
    // value -> nge
    map<int,int> maps;
    for(int i=0;i<n;i++){
        maps[nums2[i]]=nge[i];
    }
    // finding the next greater of subset of nums2
    vector<int> ans(m,-1);
    for(int i=0;i<m;i++){
        ans[i]=maps[nums1[i]];
    }
    return ans;
}

int main(){
    vector<int> nums1={4,1,2};
    vector<int> nums2={1,3,4,2};
    vector<int> ans=nextGreaterElement(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}