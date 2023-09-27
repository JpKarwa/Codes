// LEETCODE 2094 -> Finding 3-digit even numbers

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findEvenNumber(vector<int> &v){
    int n=v.size();
    vector<int> ans;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[v[i]]++;
    }
    // check each even number from 100 to 999
    for(int i=100;i<999;i+=2){
        int x=i;
        // ones digit
        int a=x%10;
        x=x/10;
        // tens digit
        int b=x%10;
        x=x/10;
        int c=x;
        if(m.find(a)!=m.end()){ // means a is present
            m[a]--;
            if(m[a]==0) m.erase(a);
            if(m.find(b)!=m.end()){
                m[b]--;
                if(m[b]==0) m.erase(b);
                if(m.find(c)!=m.end()) ans.push_back(i);
                m[b]++;
            }
            m[a]++;
        }
    }
    return ans;
}

int main(){
    vector<int> v={2,2,8,8,2};
    vector<int> ans=findEvenNumber(v);
    for(auto it:ans){
        cout<<it<<endl;
    }
}