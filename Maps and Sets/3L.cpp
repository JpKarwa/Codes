// LEETCODE 242 -> Valid Anagrams

#include<iostream>
#include<unordered_map> 
using namespace std;

bool valid1(string s,string t){
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> m1;
    unordered_map<char,int> m2;
    for(int i=0;i<s.length();i++){
        m1[s[i]]++;
    }
    for(int i=0;i<t.length();i++){
        m2[t[i]]++;
    }
    for(auto it:m1){
        char ch1=it.first;
        int freq1=it.second;
        if(m2.find(ch1)!=m2.end()){
            int freq2=m2[ch1];
            if(freq1!=freq2) return false;
        }
        else return false;
    }
    return true;
}

bool valid2(string s,string t){
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> m;
    for(int i=0;i<s.length();i++) m[s[i]]++;
    for(int i=0;i<t.length();i++) m[t[i]]--;
    for(auto it:m){
        if(it.second!=0) return false;
    }
    return true;
}

int main(){
    string s="anagram";
    string t="nagaram";
    cout<<valid1(s,t)<<" "<<valid2(s,t);
}