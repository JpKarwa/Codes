// Given 2 string s and t,return true if t is an anagram of s and false otherwise

// LEETCODE 242->Valid Anagram

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s="physicswallah";
    string t="phywallahsics";
    sort(t.begin(),t.end());
    sort(s.begin(),s.end());
    cout<<s<<endl;
    cout<<t<<endl;
    if(s==t) cout<<"Anagram";
    else cout<<"No Anagram";
}