/*
Given a stair case having n stairs
A person want to go up 
He move either one step or two step or their combination
We have to find the no. of ways*/


/*
When person at ground level it has 2 choices
*/

/*
Total no. of ways=> agar ye pehle hi 1step chal jaye phir no. of ways +
agar ye pehle hi 2step chal jaye phir no. of ways*/

// n stair path break into n-1 and n-2 stair
// n stair path ways= (n-1) stair path ways + (n-2) stair path ways

#include<iostream>
using namespace std;

int stair(int n){
    if(n==1) return 1; // 1 stair ke liye ways
    if(n==2) return 2; // 2 stair ke liye ways
    return stair(n-1)+stair(n-2);
}
int main(){
    cout<<stair(5);
}