// LEETCODE 2744 -> Find maximum number of string pairs

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


// Method 1
int maximumNumberOfStringPairs1(vector<string> &v){
    int n=v.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        string rev=v[i];
        reverse(rev.begin(),rev.end());
        for(int j=i+1;j<n;j++){
            if(v[j]==rev) cnt++;
        }
    }
    return cnt;
}

// Method 2
int maximumNumberOfStringPairs2(vector<string> &v){
    int n=v.size();
    int cnt=0;
    unordered_set<string> s;
    for(int i=0;i<n;i++){
        s.insert(v[i]);
    }
    for(int i=0;i<n;i++){
        string rev=v[i];
        reverse(rev.begin(),rev.end());
        // palindrome -> not able to make pairs
        if(v[i]==rev) continue;
        if(s.find(rev)!=s.end()){
            cnt++;
            s.erase(v[i]);
        }
    }
    return cnt;
} 

// Method 3
int maximumNumberOfStringPairs3(vector<string> &v){
    int n=v.size();
    int cnt=0;
    unordered_set<string> s;
    for(int i=0;i<n;i++){
        string rev=v[i];
        reverse(rev.begin(),rev.end());
        // if reverse exist then cnt++
        if(s.find(rev)!=s.end()) cnt++;
        else s.insert(v[i]);
    }
    return cnt;
}

int main(){
    vector<string> words={"cd","ac","dc","ca","zz"};
    cout<<maximumNumberOfStringPairs1(words)<<" ";
    cout<<maximumNumberOfStringPairs2(words)<<" ";
    cout<<maximumNumberOfStringPairs3(words)<<" ";
}