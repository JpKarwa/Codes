// LEETCODE 69 -> Sqrt(x)

#include<iostream>
using namespace std;

int mySqrt(int x) {
    int lo=0;
    int hi=x;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        long long m=mid; //mid same hi h but hmne bde dabbe me store kar liya h
        long long y=x;
        if(m*m==x) return mid;
        else if(m*m>x) hi=mid-1;
        else lo=mid+1;
    }
    return hi; 
}

int main(){
    int x=37;

    int lo=0;  //minimum square root 0 if x is 0
    int hi=x;  //jyada se jyada itna square root ho skta h

    int ans=-1;
    bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(mid*mid==x){
            flag=true;
            ans=mid;
            break;
        }
        else if(mid*mid>x){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    if(flag==true) cout<<"Square root of x:"<<ans;
    else cout<<"Square root of x:"<<hi;    //return lower bound 
}