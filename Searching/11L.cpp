// LEETCODE 875 -> KOKO EATING BANANAS
// Binary search on speed

/*
There is a bandariya. 
There are n pile and each pile has pile[i] bananas

The guard gone and come back in h hours
we have to decide the speed of koko so that she eat all bananas within h hours

Koko can eat bananas from 1 pile in 1 hour.

We have to decide minimum speed so she eats all bananas within h hours
*/

#include<bits\stdc++.h>
using namespace std;

// ye bata rha h ki mid ki speed me koko guard ke aane se pehle sare banana khalegi ya nhi
bool isPossible(int mid,vector<int>& piles, int h){
    int n=piles.size();
    long long int count=0;
    
    for(int i=0;i<n;i++){
        if(piles[i]%mid==0){
            count+=piles[i]/mid;
        }
        else{
            count+=(piles[i]/mid)+1;
        }
    }

    if(count>h) return false;
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        if(maxi<piles[i]) maxi=piles[i];
    }        
    int lo=1; // speed ko ekdum kam rkhna h
    int hi=maxi;
    int minSpeed=maxi;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(isPossible(mid,piles,h)){
            minSpeed=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return minSpeed;
}

int main(){
    vector<int> piles={3,6,7,11};
    int h=8;
    cout<<minEatingSpeed(piles,h);
}