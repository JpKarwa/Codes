// Previous Greater element

// Given an array or vector
// return an answer array of same size 
// consisting next greater element of each element
// agar kisi ke baad koi element bada nhi h toh -1

/*
3 1 2 5 4 6 2 3
-1 3 3 -1 5 -1 6 6
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> pge(vector<int> &v){
    stack<int> s;
    int n=v.size();
    vector<int> ans(n,-1);
    s.push(v[0]);
    for(int i=1;i<n;i++){
        // pop all the elements less than v[i]
        while(s.size()>0 && s.top()<=v[i]) s.pop();
        // mark the answer in answer array
        if(s.size()==0) ans[i]=-1;
        else ans[i]=s.top();
        // push v[i]
        s.push(v[i]);
    }
    return ans;
}

int main(){
    vector<int> arr={3,1,2,5,4,6,2,3};
    vector<int> ans=pge(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}