// LEETCODE 950 -> Reveal cards in increasing order

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck){
    sort(deck.begin(),deck.end());
    int n=deck.size();
    vector<int> ans(n);
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    for(int i=0;i<n;i++){
        int idx=q.front();
        q.pop();
        q.push(q.front());
        q.pop();
        ans[idx]=deck[i];
    }
    return ans;
}

int main(){
    vector<int> deck={17,13,11,2,3,5,7};
    vector<int> ans=deckRevealedIncreasing(deck);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}