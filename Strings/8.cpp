// Given two string s and p
//return an array of all the start indexex of p's anagram in s
//you may return answer in any order


//Input-> s=gigiraffe,p=gi
//output-> [0,1,2]

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s="physicswallahphysicsphy";
    string p="phy";

    int m=s.size();
    int n=p.size();

    sort(p.begin(),p.end());

    if(p.length()>s.length()) cout<<"anagram not possible";

    vector<int> v;
    for(int i=0;i<=m-n;i++){
        string temp="";
        int idx=0;
        for(int j=i;temp.length()!=n;j++){
            temp+=s[j];
            idx=i;
        }
        cout<<temp<<endl;
        sort(temp.begin(),temp.end());
        
        if(temp==p){
            v.push_back(idx);
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}