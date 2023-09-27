// LEETCODE 649 -> Dota2Senate

#include<iostream>
#include<queue>
#include<string>
using namespace std;

string dota2senate(string &s){
    int n=s.size();
    queue<int> q;  // for all string elements
    queue<int> r;  // for all radiant supporters
    queue<int> d;  // for all dire supporters
    for(int i=0;i<n;i++){
        q.push(i);
        if(s[i]=='R') r.push(i);
        else d.push(i);
    }
    // 'X' means right taken
    while(q.size()>1){
        int idx=q.front();
        char party=s[idx];
        if(party=='X'){
            q.pop();
        }
        else if(party=='R'){
            // check for victory
            if(d.size()==0) return "Radiant";
            // take the right of next dyre supporter
            int idx1=d.front();
            s[idx1]='X';
            d.pop();
            int idx2=r.front();
            r.pop();
            r.push(idx2);
            int idx3=q.front();
            q.pop();
            q.push(idx3);
        }
        else if(party=='D'){
            // check for victory
            if(r.size()==0) return "Dire";
            // take the right of next radiant supporter
            int idx1=r.front();
            s[idx1]='X';
            r.pop();
            int idx2=d.front();
            d.pop();
            d.push(idx2);
            int idx3=q.front();
            q.pop();
            q.push(idx3);
        }
    }
    if(s[q.front()]=='R') return "Radiant";
    else return "Dire";
}

int main(){
    string s="RDD";
    cout<<dota2senate(s);
}