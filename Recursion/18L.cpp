// LEETCODE 22 -> Generate parentheses

/*
Given n pairs of parentheses,
write a function to generate all combinations of well-formed parentheses.
*/

/*
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/
// 3 pairs means 6 brackets

// for n=1
// () -> well formed
// )( -> not well formed

// for n=2
// ()() , (()) -> well formed
// ))(( , )()( -> not well formed


// at every index no. of opening brackets > no. of closing brackets

// base case rkhenge hm closing == n because opening toh hmara bahut pehle hi n ke equal ho jayenge

#include<iostream>
using namespace std;

void generateparanetheses(string s,int open,int close,int n){
    if(close==n){
        cout<<s<<endl;
        return;
    }
    if(open<n) generateparanetheses(s+'(',open+1,close,n);
    if(open>close) generateparanetheses(s+')',open,close+1,n);
}

int main(){
    int n=3;
    generateparanetheses("",0,0,n);
}