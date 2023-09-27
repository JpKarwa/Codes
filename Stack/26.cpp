// POSTFIX to INFIX

#include<iostream>
#include<stack>
using namespace std;

string solve(string a,string b,char ops){
    string ans="";
    ans+=a;
    ans.push_back(ops);
    ans+=b;
    return ans;
}

int main(){
    string post="79+4*8/3-";
    int n=post.size();
    stack<string> val;
    for(int i=0;i<n;i++){
        if(post[i]>=48 && post[i]<=57){
            val.push(to_string(post[i]-'0'));
        }
        else{
            // actual evaluation
            string val2=val.top();
            val.pop();
            string val1=val.top();
            val.pop();
            string ans=solve(val1,val2,post[i]);
            val.push(ans);
        }
    }
    cout<<val.top();
}