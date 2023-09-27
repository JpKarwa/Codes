// POSTFIX EVALUATION

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

int main(){
    string post="79+4*8/3-";
    int n=post.size();
    stack<int> val;
    for(int i=0;i<n;i++){
        if(post[i]>=48 && post[i]<=57){
            val.push(post[i]-'0');
        }
        else{
            // actual evaluation
            int val2=val.top();
            val.pop();
            int val1=val.top();
            val.pop();
            int ans=solve(val1,val2,post[i]);
            val.push(ans);
        }
    }
    cout<<val.top();
}