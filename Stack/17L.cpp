// LEETCODE 682 ->Baseball Game

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int calPoints(vector<string> &ops){
    stack<int> s;
    for(int i=0;i<ops.size();i++){  // push addition of top 2 score
        if(ops[i]=="+"){
            int temp=s.top();
            s.pop();
            int newScore=s.top()+temp;
            s.push(temp);
            s.push(newScore);
        }
        else if(ops[i]=="C"){   // pop the score at top
            s.pop(); 
        }
        else if(ops[i]=="D"){  // push double score of score at top
            int newScore=2*s.top();
            s.push(newScore);
        }
        else{   // push a new score
            s.push(stoi(ops[i]));
        }
    }
    int ans=0;
    while(s.size()>0){
        ans+=s.top();
        s.pop();
    }
    return ans;
}

int main(){
    vector<string> operations={"5","2","C","D","+"};
    cout<<calPoints(operations); 
}