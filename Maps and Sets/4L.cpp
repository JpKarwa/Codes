// LEETCODE 1 -> Two sum

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &v,int target){
    int n=v.size();
    vector<int> ans;
    unordered_map<int,int> m;
    // key -> element
    // value->index
    for(int i=0;i<n;i++){
        int rem=target-v[i];
        if(m.find(rem)!=m.end()){
            ans.push_back(m[rem]);
            ans.push_back(i);
            break;
        }
        else{
            m[v[i]]=i;
        }
    }
    return ans;
}

int main(){
    vector<int> v={2,7,11,15};
    int target=13;
    vector<int> ans=twoSum(v,target);
    for(auto it:ans){
        cout<<it<<" ";
    }
}