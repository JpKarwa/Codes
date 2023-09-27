// GCD OR HCF OF 2 NUMBERS

#include<bits\stdc++.h>
using namespace std;

int hcf(int a,int b){
    for(int i=min(a,b);i>=2;i--){
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}

int gcd(int a,int b){
    if(a==0) return b;    
    gcd(b%a,a);
}
int main(){
    int a=27;
    int b=45;
    cout<<gcd(a,b);
}

// time complexity is log(a+b)