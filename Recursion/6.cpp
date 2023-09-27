// remove occurence of 1 from array
// push_back has return type void


#include<bits\stdc++.h>
using namespace std;

void removeOnes(vector<int> org,vector<int> &ans,int idx){
    if(idx==org.size()) return;
    int val=org[idx];
    if(val==1) removeOnes(org,ans,idx+1);
    else {
        ans.push_back(val);
        removeOnes(org,ans,idx+1);
    }
}

int main(){
    vector<int> arr={1,2,3,1,1,4,1,7,2,1,1};
    int n=arr.size();
    vector<int> naya;
    removeOnes(arr,naya,0);
    for(int i=0;i<naya.size();i++){
        cout<<naya[i]<<" ";
    }
}