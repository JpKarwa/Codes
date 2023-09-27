// LEETCODE 1944 -> No. of visible people in a queue

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> canSeePersonCount(vector<int> &heights){
    int n=heights.size();
    vector<int> ans(n,0);
    stack<int> s;
    s.push(heights[n-1]);
    for(int i=n-2;i>=0;i--){
        int count=0;
        while(s.size()>0 && s.top()<=heights[i]){
            s.pop();
            count++;
        } 
        if(s.size()!=0) count++;
        ans[i]=count;
        s.push(heights[i]);
    }
    return ans;
}
int main(){
    vector<int> heights={10,6,8,5,11,9};
    vector<int> ans=canSeePersonCount(heights);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}