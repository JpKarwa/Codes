// Balanced Brackets

// Given a string and we having only two elements in string '(' and ')'
// We have to check that given string is balanced or not
// Agar koi closing dikh rha h toh uska opening usse pehle hi aana chahiye

/*
()()()  -> True
(())()  -> True
()((()) -> False
)()(    -> False
((()())) -> True
*/


/*
Opening bracket -> push into stack
closing brakcet -> see the top of stack and analyse what to do
                   if top have opening bracket pop
                   else if stack is empty return false means unbalanced
if after doing all of this stack size is 0 then balanced
*/

#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string s){
    stack<char> st;
    int i=0;
    int n=s.length();
    if(n%2) return false;
    while(i<n){
        if(s[i]=='(') st.push(s[i]);
        else{
            if(st.size()==0) return false;
            else st.pop();
        }
        i++;
    }
    if(st.size()==0) return true;
    else return false;
} 

int main(){
    string s=")()(";
    cout<<isBalanced(s);
}