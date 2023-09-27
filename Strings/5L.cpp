// Given 2 string s and t determine if they are isomorphic

//LEETCODE 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s="badc";
    string t="baba";

    if(s.length()!=t.length()){
        cout<<"No ismorphic";
        return 0;
    }
    
    //creating a vector 
    vector<int> v(150,1000);   //1000 se upar hota hi nhi h difference;
    //checking isomorphic with perspective of s
    for(int i=0;i<s.length();i++){
        int idx=int(s[i]);
        if(v[idx]==1000) v[idx]=s[i]-t[i];
        else if(v[idx]!=s[i]-t[i]){
            cout<<"No isomorphic";
            return 0;
        }
    }

    //empyting the vector v
    for(int i=0;i<150;i++){
        v[i]=1000;
    }
    //checking isomorphic with perspective of t
    for(int i=0;i<t.length();i++){
        int idx=int(t[i]);
        if(v[idx]==1000) v[idx]=t[i]-s[i];
        else if(v[idx]!=t[i]-s[i]){
            cout<<"No isomorphic";
            return 0;
        }
    }
    cout<<"Isomorphic";
    
    return 0;
}