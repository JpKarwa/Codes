//given the sentence given the word that is lexicographhically max;

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s="i am a pwian";
    stringstream ss(s);
    string temp;
    vector<string> v;
    while(ss>>temp){
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    cout<<v[3];
}