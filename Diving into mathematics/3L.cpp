// Leetcode 2483-> Minimum Penalty for a shop

#include<bits\stdc++.h>
using namespace std;

int bestClosingTime(string customers) {
    int n=customers.length();
    vector<int> pref(n+1,0);         // N ki penalties
    vector<int> suff(n+1,0);        // Y ki penalties
    int nCount=0;

    // no. of N before ith hour
    for(int i=1;i<n+1;i++){
        if(customers[i-1]=='N') nCount++;
        pref[i]=nCount;
    }
    // no. of Y after and including ith hour
    int yCount=0;
    for(int i=n-1;i>=0;i--){
        if(customers[i]=='Y')  yCount++;
        suff[i]=yCount;
    }
    int minPenalty=INT_MAX;
    int minHr=INT_MAX;
    for(int i=0;i<=n;i++){
        pref[i]+=suff[i];
        minPenalty=min(minPenalty,pref[i]);
    }
    for(int i=0;i<=n;i++){
        if(pref[i]==minPenalty){
            minHr=i;
            break;
        }
    }
    return minHr;
}

int main(){
    string customers1="YYNY";
    string customers2="NNNN";
    string customers3="YYYY";
    cout<<bestClosingTime(customers1);
    cout<<bestClosingTime(customers2);
    cout<<bestClosingTime(customers3);
}