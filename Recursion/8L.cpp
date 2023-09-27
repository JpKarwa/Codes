// Subsets of an array
// LEETCODE 78

#include<bits\stdc++.h>
using namespace std;

void printSubsets1(vector<int> org,vector<int> ans,int idx,vector<vector<int>> &answer){
    //base case
    if(idx==org.size()){
        answer.push_back(ans);
        return;
    }
    printSubsets1(org,ans,idx+1,answer);  
    ans.push_back(org[idx]);
    printSubsets1(org,ans,idx+1,answer);  
}

int main(){
    vector<int> arr={1,2,3};
    vector<int> output;
    vector<vector<int>> ans;
    printSubsets1(arr,output,0,ans);

    for(int i=0;i<ans.size();i++){
        vector<int> temp=ans[i];
        for(int j=0;j<temp.size();j++){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
}