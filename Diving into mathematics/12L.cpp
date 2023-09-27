// LEETCODE 2389 -> Longest Subsequence with limited sum

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> answerQueries1(vector<int> &v,vector<int>  &q){
    int n=v.size();
    int m=q.size();
    vector<int> ans(m,0);
    sort(v.begin(),v.end());   // TC-> O(n*logn)
    vector<int> pref(n,0);
    pref[0]=v[0];
    for(int i=1;i<n;i++){
        pref[i]=v[i]+pref[i-1];
    }
    for(int i=0;i<m;i++){     // O(m*n)
        int len=0;
        for(int j=0;j<n;j++){
            if(pref[j]>q[i]) break;
            len++;
        }
        ans[i]=len;
    }
    return ans; // TC=O(n*(m+logn)-> O(n*m)
}

vector<int> answerQueries2(vector<int> &v,vector<int>  &q){
    int n=v.size();
    int m=q.size();
    vector<int> ans(m,0);
    sort(v.begin(),v.end());   // TC-> O(n*logn)
    vector<int> pref(n,0);
    pref[0]=v[0];
    for(int i=1;i<n;i++){
        pref[i]=v[i]+pref[i-1];
    }
    for(int i=0;i<m;i++){     // O(m*logn)
        int len=0;
        int s=0;
        int e=n-1;
        // binary search
        while(s<=e){
            int mid=s+(e-s)/2;
            if(pref[mid]>q[i]){
                e=mid-1;
                // age wale part me kuch nhi milega
            }
            else{
                len=mid+1;
                s=mid+1;
            }
        }
        ans[i]=len;
    }
    return ans; // TC=O[(m+n)*logn]-> O(n*m)
}

int main(){
    vector<int> nums={4,5,2,1};
    vector<int> queries={3,10,21};
    vector<int> ans=answerQueries1(nums,queries);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}