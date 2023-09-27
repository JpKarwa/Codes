// remove occurence of a from string

#include<iostream>
using namespace std;

void removeChar(string org,string ans){
    if(org.size()==0){
        cout<<ans;
        return;
    }
    char ch=org[0];
    if(ch=='a') removeChar(org.substr(1),ans);
    else removeChar(org.substr(1),ans+ch);
}
// jb substr ka use krrhe h toh vha ek brand new string ban rhi toh ye bekkar approach h

void removeCharOpt(string org,string ans,int idx){
    if(idx==org.length()){
        cout<<ans;
        return;
    }
    char ch=org[idx];
    if(ch=='a') removeCharOpt(org,ans,idx+1);
    else removeCharOpt(org,ans+ch,idx+1);
}

int main(){
    string s="Vijay Karwa";
    removeCharOpt(s,"",0);
    // string sn="";
    // for(int i=0;s[i]!='\0';i++){
    //     if(s[i]!='a') sn.push_back(s[i]);
    // }
    // cout<<sn;
}