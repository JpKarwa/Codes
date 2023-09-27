// LEETCODE 779 -> Kth symbol in grammar

// odd position pe jo zeroes h vo 0 se aa rhe h
// even position pe jo zeroes h vo 1 se geerate ho rhe h
// odd position pe jo ones h vo 1 se aa rhe h
// even position pe jo ones h vo 0 se aa rhe h

// O(n) time complexity

#include<iostream>
using namespace std;

int kthGrammar(int n, int k) {
    if(n==0) return 0;
    if(k%2==0) return !kthGrammar(n-1,k/2);
    else return kthGrammar(n-1,k/2+1);   
}
int main(){
    int n=3,k=2;
    cout<<kthGrammar(n,k);
}