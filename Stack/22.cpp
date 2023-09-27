// INFIX TO PREFIX CONVERSION

#include<iostream>
#include<stack>
using namespace std;

string solve(string a,string b,char ch){
    string ans=ch+a+b;
    return ans;
}

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    return 2;
}

int main(){
    string s="2+6*4/8-3";
    // creating 2 stack
    stack<string> val;
    stack<char> op;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-'0'));
        }
        else{
            if(op.size()==0 || prio(s[i])>prio(op.top())) op.push(s[i]);
            else{
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    char ch=op.top();
                    op.pop();
                    string s2=val.top();
                    val.pop();
                    string s1=val.top();
                    val.pop();
                    string res=solve(s1,s2,ch);
                    val.push(res);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        char ch=op.top();
        op.pop();
        string s2=val.top();
        val.pop();
        string s1=val.top();
        val.pop();
        string res=solve(s1,s2,ch);
        val.push(res);
    }
    cout<<val.top();
}