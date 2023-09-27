// INFIX EVALUATION WITH BRACKETS

#include<iostream>
#include<stack>
using namespace std;

int solve(int a,int b,char ops){
    if(ops=='+'){
        return a+b;
    }
    else if(ops=='-'){
        return a-b;
    }
    else if(ops=='*'){
        return a*b;
    }
    else if(ops=='/'){
        return a/b;
    }
}

int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    return 2;
}

int main(){
    string s="(7+9)*4/8-3";
    // we need 2 stack
    stack<int> val;
    stack<char> op;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-'0');
        else{
            if(op.empty() || s[i]=='(' || op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.size()>0 && op.top()!='('){
                    char ch=op.top();
                    op.pop();
                    int val2=val.top();
                    val.pop();
                    int val1=val.top();
                    val.pop();
                    int ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(s[i])>prio(op.top()))  op.push(s[i]);
            else{
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    char ch=op.top();
                    op.pop();
                    int val2=val.top();
                    val.pop();
                    int val1=val.top();
                    val.pop();
                    int ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        char ch=op.top();
        op.pop();
        int val2=val.top();
        val.pop();
        int val1=val.top();
        val.pop();
        int ans=solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top();
}