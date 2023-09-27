/*
Given a non negative integer c
Kinhi do number a and b ke square ka sum c ke barabar h ya nhi 
*/

//LEETCODE 633

#include<iostream>
#include<bits\stdc++.h>
using namespace std;

bool isPerfectSquare(int n){
    int root=sqrt(n);
    if(root*root==n) return true;
    return false;
}
bool judgeSquareSumBF(int c){
    int x=0;
    int y=c;
    while(x<=y){
        if(isPerfectSquare(x) && isPerfectSquare(y)) return true;
        else{
            x++;
            y--;
        }
    }
    return false;
}

bool judgeSquareSum(int c) {
    int x=0;
    int y=c;

    while(x<=y){
        if(isPerfectSquare(x) && isPerfectSquare(y)){
            return true;
        }
        else if(!isPerfectSquare(y)){
            y=(int)sqrt(y)*(int)sqrt(y);
            x=c-y;
        }
        else{
            x=((int)sqrt(x)+1)*((int)sqrt(x)+1);
            y=c-x;
        }
    }
    return false;
}

int main(){
    int c=41;
    cout<<judgeSquareSumBF(c)<<endl;
    cout<<judgeSquareSum(c);
}



/*
x=> 0 5 9 16
y=> 41 36 32 25
*/



// y mera perfect square nhi h toh use chota bana do
// x mera perfect square nhi h toh x ko bada bana do

// TC -> 
// M1 -> c/2 iteration then O(c)
// M2 -> O(sqrt(c))

/*
c=7
x -> 0 3 4
y -> 7 4 3
3 operation-> sqrt(7)+1
O(sqrt(7)+1) => O(sqrt(c))
*/