// Print the nth fibonacci number
// 1 1 2 3 5 8 ......
// fib(n)=fib(n-1)+fib(n-2)

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the term of fibonaaci series to print:";
    cin>>n;
    int n_minus_one=1;
    int n_minus_two=1;
    int nth=0;
    for(int i=1;i<=(n-2);i++){
        nth=n_minus_one+n_minus_two;
        n_minus_two=n_minus_one;
        n_minus_one=nth;
    }
    cout<<nth;

}