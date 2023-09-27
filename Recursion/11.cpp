// Increasing subsequences
// Given a number n and length k
// We have to print all the increasing sequences of length k from first n natural number

/*
Sare subsets nikal lenge phir phir jiska size k ke barabar h unko print karwa denge
*/

#include<bits\stdc++.h>
using namespace std;

void subsequences(int arr[],int n,int idx,vector<int> ans,int k){
    if(idx==n){
        if(ans.size()==k){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(ans.size()+(n-idx)<k) return; //time complexity better ho jayegi
    subsequences(arr,n,idx+1,ans,k);
    ans.push_back(arr[idx]);
    subsequences(arr,n,idx+1,ans,k);
}

int main(){
    int arr[]={1,2,3,4,5};
    vector<int> ans;
    vector<vector<int>> v;
    subsequences(arr,5,0,ans,3);
}