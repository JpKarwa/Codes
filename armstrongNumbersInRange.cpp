/* Write a program to print out all Armstrong numbers between 1 and 500. If the sum of cubes of
each digit of the number is equal to the number itself, then the number is called an Armstrong
number.*/

#include<iostream>
using namespace std;

int main(){
    for(int i=1;i<=500;i++){
        int sumOfCubes=0;
        int n=i;
        while(n>0){
            int lastDigit=n%10;
            sumOfCubes+=lastDigit*lastDigit*lastDigit;
            n=n/10;
        }
        if(i==sumOfCubes){
            cout<<i<<endl;
        }
    }
}