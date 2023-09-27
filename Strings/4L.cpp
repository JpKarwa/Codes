// Input n string and wap to 
// find longest common prefix string of all the strings

// LEETCODE -> Longest Common Prefix
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    vector<string> v={"flower","flow","flight"};
    int n=v.size();
    string c="";//to store longest common prefix
    if(n==1){
        cout<<v[0];
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    string s1=v[0];
    string s2=v[n-1];
    for(int i=0;i<min(s1.size(),s2.size());i++){
        if(s1[i]==s2[i]) c+=s1[i];
    }
    cout<<c;
}