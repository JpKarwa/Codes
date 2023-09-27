// Fist negative in each window of size k

// if no negative in window then put 0

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> firstNegative(vector<int> &v,int k){
    queue<int> q;
    vector<int> ans;
    int count=0;
    int n=v.size();
    // pushing all negative element index at queue
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            q.push(i);
        } 
    }
    // checking each window
    for(int i=0;i<=n-k;i++){
        while(q.size()>0 && q.front()<i){
            q.pop();
        }
        if(q.size()==0 || q.front()>=i+k){
            ans.push_back(0);
        }
        else{
            ans.push_back(v[q.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int> arr={0,-1,-2,3,4,-5,6,4,7,-8};
    int k=3;
    vector<int> ans=firstNegative(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}