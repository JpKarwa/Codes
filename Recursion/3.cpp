// Tower of hanoi

// minimum no. of moves 2 to the power n - 1

// print the ways im which we move the disk

// For n disks
// upar ki n-1 disks ko recursion ke through src to helper pahuchao
// Biggest disk ko src to dest pahuchado
// n-1 disk ko helper to dest pahuchado
// src helper destination change ho gi har subproblem ke liye


#include<iostream>
using namespace std;

void towerOfHanoi(int n,char src,char helper,char dest){
    if(n==0) return;

    towerOfHanoi(n-1,src,dest,helper); // upar ki n-1 disks ko A to B pahuchayenge with the help of C
    cout<<src<<"->"<<dest<<endl;
    towerOfHanoi(n-1,helper,src,dest);
}
int main(){
    int no_of_disk=4;
    towerOfHanoi(no_of_disk,'A','B','C');
}