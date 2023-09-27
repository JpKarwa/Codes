// LEETCODE 38 ->Count and Say

#include<iostream>
using namespace std;

string countAndSay(int n){
    if(n==1) return "1";
    string s=countAndSay(n-1);
    // cout<<s<<" ";
    string ztr="";
    int freq=1;
    char ch=s[0];
    for(int i=1;i<s.length();i++){
        char dh=s[i];
        if(ch==dh) freq++;
        else{
            ztr+=to_string(freq)+ch;
            freq=1;
            ch=dh;
        }
    }
    ztr+=to_string(freq)+ch;
    return ztr;
}

int main(){
    cout<<countAndSay(3);
}