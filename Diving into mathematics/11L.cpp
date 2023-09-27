// LEETCODE 1402 -> Reducing Dishes

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// all dishes with +ve satisfaction value must be staken
// some of the dishes with negative value can be taken
// mujhe apna index dhundna h jaha se hamara answer aajayega

// find the index or pivor index

int maxLiketime(vector<int> &v){
    int n=v.size();
    sort(v.begin(),v.end());
    vector<int> suff(n,-1);
    suff[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i]=v[i]+suff[i+1];
    }
    int idx=-1;
    for(int i=0;i<n;i++){
        if(suff[i]>=0){
            idx=i;
            break;
        }
    }
    if(idx==-1) return 0;
    int ans=0;
    int x=1;
    for(int i=idx;i<n;i++){
        ans+=x*v[i];
        x++;
    }
    return ans;
}

int main(){
    vector<int> satisfaction={-1,-8,0,5,-9};
    cout<<maxLiketime(satisfaction);
}


// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         sort(satisfaction.begin(),satisfaction.end());
//         for(auto i: satisfaction) cout<<i<<" ";
//         int sum=0;
//         for(int i=0;i<satisfaction.size();i++){
//             int x=1,s=0;
//             for(int j=i;j<satisfaction.size();j++){
//                 s+=satisfaction[j]*(x++);
//             }
//             sum=max(s,sum);
//         }
//         return sum;
//     }
// };