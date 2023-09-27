// Remove consecutive duplicates in a string
// aaabbcddaabffg -> abcdabfg

#include<bits\stdc++.h>
using namespace std;

void removeDups(string &s){
    stack<char> st;
    if(s.length()==1) return;
    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(st.top()==s[i]) continue;
        else st.push(s[i]);
        // if(st.top()!=s[i]) st.push(s[i]);
    }
    s="";
    while(st.size()){
        s+=st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
}

int main(){
    string s="aaabbcddaabffg";
    removeDups(s);
    cout<<s;
}