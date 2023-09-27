// Find out whether string is palindrome or not using recursion

#include<iostream>
using namespace std;

bool iterative(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

bool recursive(string s,int i,int j){
    //base case
    if(i>j) return true;

    //calls
    if(s[i]!=s[j]) return false;
    return recursive(s,i+1,j-1);
}

int main(){
    string s="racecar";
    cout<<recursive(s,0,s.size()-1);
}