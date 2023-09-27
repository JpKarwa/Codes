// LEETCODE 1207 -> Unique Number of occurences

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

bool uniqueOccurences(vector<int> &arr){
    int n=arr.size();
    // create a map
    unordered_map<int,int> m;
    // key->element
    // value->freq
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    // creating a set
    unordered_set<int> s;
    for(auto p:m){
        int freq=p.second;
        if(s.find(freq)!=s.end()){   // frequency already exist
            return false;
        }
        else{  // frequency not exist
            s.insert(freq);
        }
    }
    return true;
}

int main(){
    vector<int> arr={1,2,2,1,1,3};
    cout<<uniqueOccurences(arr);
}