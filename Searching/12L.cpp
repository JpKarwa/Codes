// LEETCODE 2187 -> Minimum Time to Complete Trips
// Binary Search on time

/*
Given an array time where ith bus take time[i] to complete one trip
Given a variable total trips which denotes total no. of trips by all buses
hme at least total no. of trips complete krni h

hme total trip complete krne me minimum kitna time laga

*/

#include<bits\stdc++.h>
using namespace std;

bool isPossible(long long mid,vector<int>& time, int totalTrips){
    long long trips=0; 
    int n=time.size();
    for(int i=0;i<n;i++){
        trips+=mid/(long long)time[i];
    }
    if(trips<totalTrips) return false;
    else return true;
}

long long minimumTime(vector<int>& time, int totalTrips) {
    long long n=time.size();
    long long maxi=0;
    for(int i=0;i<n;i++){
        if(maxi<time[i]) maxi=time[i];
    }        
    long long lo=1; // speed ko ekdum kam rkhna h
    long long hi=(long long)maxi*(long long)totalTrips;       // maximum time 15 hrs,5 trips krne me lagenge agar kewal 3rd bus chal rhi h
    long long minTime=-1;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        // cout<<isPossible(mid,time,totalTrips)<<endl;
        if(isPossible(mid,time,totalTrips)){
            minTime=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return minTime;
}
int main(){
    vector<int> time={1,2,3};
    int totalTrips=3;
    cout<<minimumTime(time,totalTrips);
}
