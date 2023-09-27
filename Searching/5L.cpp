// LEETCODE 441
/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
Given the integer n, return the number of complete rows of the staircase you will build.

Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
*/

/*
k hamara 1<=K<=n hoga

1+2+3+...+K <= n
k(k+1)/2<=n
*/

// Lower bound ka question h

// overflow se bachne ke liye long long use krna h

#include<iostream>
using namespace std;

int main(){
    int n=13;
    
    int lo=1;
    int hi=n;

    bool flag=false;
    while(lo<=hi){
        int k=lo+(hi-lo)/2;  
        if(k*(k+1)/2 > n) hi=k-1;
        else if(k*(k+1)/2 < n) lo=k+1;
        else if(k*(k+1)/2 == n){
            flag=true;
            cout<<k;
            break;
        }
    }

    if(flag==false) cout<<hi;
}

/*
k(k+1)/2 <= n
k*(k+1) <= 2*n
t=k(k+1)
t <= 2*n

k(k+1)-t=0
on solving this
we get
k= [-1 +- sqrt(1+4t)] / 2

ek value positive hogi aur ek negative but negative not possible so we take only positive
k= [-1 + sqrt(1+4t)] / 2

*/

/*
ll t=ll(2*n)
ll d=1+(4*t)
int k=sqrt(-1+sqrt(d))/2;
return k;
*/