// LEETCODE 1052 -> Grumpy Bookstore owner

#include<iostream>
#include<vector>
using namespace std;

// BRUTE FORCE
// int solve(vector<int>& customers, vector<int>& grumpy){
//         int n=customers.size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(grumpy[i]==0) ans+=customers[i];
//         }
//         return ans;
//     }
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
//         int k=minutes;
//         int n=customers.size();
//         int maxc=0;
//         vector<int> temp=grumpy;
//         for(int i=0;i<n-k+1;i++){
//             vector<int> temp=grumpy;
//             for(int j=i;j<i+k;j++){
//                 temp[j]=0;
//             }
//             int c=solve(customers,temp);
//             maxc=max(c,maxc);
//         }
//         return maxc;
//     }

// optimised 
// find the window that has most loss of satisfaction
// loss of satisfaction= sum of customers when grumpy[i]=1
int maxSatisfied(vector<int> &customers,vector<int> &grumpy,int minutes){
    int k=minutes;    // window size
    int n=customers.size();
    int loss=0;
    // find the loss of satisfaction in first k elements
    for(int i=0;i<k;i++){
        if(grumpy[i]==1) loss+=customers[i];
    }
    // find the best window that leads to maximum satisfaction
    int maxLoss=loss;
    int start=0;   // best window ka start
    int i=1;
    int j=k;
    while(j<n){
        if(grumpy[j]==1) loss+=customers[j];
        if(grumpy[i-1]==1) loss-=customers[i-1];
        if(maxLoss<loss){
            maxLoss=loss;
            start=i;
        }
        i++;
        j++;
    }
    // filling maximum loss window with 0's
    for(int i=start;i<start+k;i++){
        grumpy[i]=0;
    }
    // find the maxSatisified customers
    int maxs=0;
    for(int i=0;i<n;i++){
        if(grumpy[i]==0) maxs+=customers[i];
    }
    return maxs;
}

int main(){
    vector<int> customers={1,0,1,2,1,1,7,5};
    vector<int> grumpy={0,1,0,1,0,1,0,1};
    int minutes=3;
    cout<<maxSatisfied(customers,grumpy,minutes);
}