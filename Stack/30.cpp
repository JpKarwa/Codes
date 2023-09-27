// PREFIX TO POSTFIX

#include<iostream>
#include<stack>
using namespace std;

string solve(string a,string b,char ch){
    string s="";
    s+=a;
    s+=b;
    s.push_back(ch);
    return s;
}

// pehle val1 ko pop krenge phir val2 ko
int main(){
    string post="-/*+79483";
    int n=post.size();
    stack<string> val;
    for(int i=n-1;i>=0;i--){
        if(post[i]>=48 && post[i]<=57){
            val.push(to_string(post[i]-'0'));
        }
        else{
            // actual evaluation
            string val1=val.top();
            val.pop();
            string val2=val.top();
            val.pop();
            string ans=solve(val1,val2,post[i]);
            val.push(ans);
        }
    }
    cout<<val.top();
}