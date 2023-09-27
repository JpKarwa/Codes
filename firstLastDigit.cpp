/* Write function to print out first and last digit of a number without return anything.*/

#include<iostream>
using namespace std;

void digits(int *p){
    int ld=(*p)%10;
    while((*p)>9){
        int digit=(*p)%10;
        (*p)/=10;
    }
    int fd=*p;
    cout<<"First Digit:"<<fd<<endl;
    cout<<"Last Digit:"<<ld;
}
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    digits(&n);
}