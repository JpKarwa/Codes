// LEETCODE 20 -> Valid Parantheses
// ([}}]) -> False
// (){}}{ -> False
// ){ -> False;

#include<iostream>
#include<stack>
using namespace std;

bool validParentheses(string s){
    int n=s.length();
    if(n%2!=0) return false;
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.size()==0) return false;
            bool a=(s[i]==')') && (st.top()=='(');
            bool b=(s[i]=='}') && (st.top()=='{');
            bool c=(s[i]==']') && (st.top()=='[');
            if(a || b || c) st.pop();
            else return false;
        }
    }
    return !st.size();
    // if(st.size()==0) return true;
    // else return false;
}

int main(){
    string s="){";
    cout<<validParentheses(s);
}