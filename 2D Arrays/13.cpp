/*
Given a matrix ‘A’ of dimension n x m and 2 coordinates (l1, r1) and (l2, r2). Return the sum of the
rectangle from (l1,r1) to (l2, r2).

Input 1:
1 2 -3 4
0 0 -4 2
1 -1 2 3
-4 -5 -7 0
l1 = 1, r1 = 2 , l2 = 3 , r2 = 3
Output 1: -4

Input 2:
1 2 -3 4
0 0 -4 2
1 -1 2 3
-4 -5 -7 0
l1 = 1, r1 = 0 , l2 = 0 , r2 = 3
Output 1: 2

*/

#include<iostream>
using namespace std;

int main(){
    int arr[4][4]={1,2,-3,4,0,0,-4,2,1,-1,2,3,-4,-5,-7,0};
    int l1=1,r1=2,l2=3,r2=3;
    int sum=0;
    for(int i=min(l1,l2);i<=max(l1,l2);i++){
        for(int j=min(r1,r2);j<=max(r1,r2);j++){
            sum+=arr[i][j];
        }
    }
    cout<<sum;
}