// LEETCODE - 1011
// BInary search on capacity

/*
Given an array of weights of object and a variable with name d
We have to move this objects to another place via ship in d days
We have to put the objects order wise means object 1 first then object 2
We have to find minimum capacity of ship
*/

/*
lo=max element of array agar hum minimum rkhenge toh usse bade weight wala object toh ja hi nhi payega
hi=sum of array(all objects move in 1 day)
*/

/*
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
*/

#include<bits\stdc++.h>
using namespace std;

bool isPossible(int capacity,vector<int> &weights,int days){
    int n=weights.size();
    int m=capacity;  //har din ki capacity denote kar rha h
    int count=1;  //given capacity ke liye kitne din lage
    for(int i=0;i<n;i++){
        if(m>=weights[i]){
            m-=weights[i];
        }
        else{
            count++;
            m=capacity;
            m-=weights[i];
        }
    }
    if(count>days) return false;
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int maxi=0;
    int sum=0;
    int n=weights.size();
    for(int i=0;i<n;i++){
        if(weights[i]>maxi) maxi=weights[i]; 
        sum+=weights[i];
    }
    int lo=maxi;
    int hi=sum;
    int minCapacity=sum;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(isPossible(mid,weights,days)){
            minCapacity=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return minCapacity;
}

int main(){
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int d=5;       //maximum days h task pura krne ke liye
    cout<<shipWithinDays(weights,d);
}

/*
TC = n(sum+maxi) + nlog(sum-maxi)(for binary search and isPossible)
TC = O(n*logn)
*/
