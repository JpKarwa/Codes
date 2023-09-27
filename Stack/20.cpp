// INFIX EVALUATION without brackets

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
    string s="2+6*4/8-3";
    // we need 2 stack
    stack<int> val;
    stack<char> op;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48 && s[i]<=57){  // digit
            val.push(s[i]-'0');
        }
        else{
            if(op.size()==0 || prio(s[i])>prio(op.top())) op.push(s[i]);
            else{
                // val1 op val2
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
    // op stack can have values
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