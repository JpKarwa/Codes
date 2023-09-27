// Find the doublet in the array whose sum is equal to x
// Given x and an array or vector

// LEETCODE -> TWO SUM (doublets ke index batane h)

// v={1,3,2,4,3,4,1,6} , x=7

// output->{(0,7),(1,3),(1,5),(3,4),(4,5),(6,7)}

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={1,3,2,4,3,4,1,6};
    int x=7;

    // vector<int> doubletsIndex; //store doublets index
    // vector<int> doublets;  //store doublets
    for(int i=0;i<=v.size()-2;i++){
        for(int j=i+1;j<=v.size()-1;j++){
            if(v[i]+v[j]==x){
                cout<<"("<<i<<","<<j<<")"<<endl;
                // pair<int,int> p1,p2;
                // p1.first=i;
                // p1.second=j;
                // p2.first=v[i];
                // p2.second=v[j];
                // doubletsIndex.push_back(p1);
                // doublets.push_back(p2);
            }
        }
    }

    // for(int i=0;i<doubletsIndex.size();i++){
    //     cout<<doubletsIndex[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<doublets.size();i++){
    //     cout<<doublets[i]<<" ";
    // }
}

/*
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int,int> m;
    for(int i=0;i<nums.size();i++){
        if(m.count(target-nums[i])){
            ans.push_back(i);
            ans.push_back(m[target-nums[i]]);
            return ans;
        }
        m[nums[i]]=i;
    }
    return {};
}
*/