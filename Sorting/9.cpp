//range of K

/*
arr=[5,4,3]
o/p = 5
arr=[|5-5|,|4-5|,|4-3|] = [0,1,2] => almost sorted

arr=[5,3,8]
o/p = 5
*/

/*
arr=[5,2,10]
arr=[|5-K|,|2-K|,|10-K|]
if it is sorted then
|2-K|>= |5-K| and |10-K|>=|2-K|

(2-K)^2 >= (5-K)^2
(K-2)^2 - (K-5)^2 >= 0
(K-2+K-5)(K-2-K+5) >= 0
(2K-7)(3)>=0
this inequality is true when both brackets are +ve or both are -ve
one is +ve so other one is also be +ve
(2K-7)>=0
K>=7/2
K>=3.5
K>=4 (lower limit of K)

(10-K)^2 >= (2-K)^2
(K-10)^2 - (K-2)^2 >= 0
(K-10+K-2)(K-10-K+2) >= 0
(2K-12)(-8)>=0
this inequality is true when both brackets are +ve or both are -ve
one is -ve so other one is also be -ve
(2K-12)<=0
K<=6 (upper limit of K)
*/

/*
Generalised way

|K-a[m]|>=|K-a[m-1]|
(2K-a[m]-a[m-1])(a[m-1]-a[m])>=0

if a[m-1]-a[m] >=0 then
(2K-a[m]-a[m-1])>=0
K>=(a[m]+a[m-1])/2  => K ki min value

if a[m-1]-a[m]<0 then
(2K-a[m]-a[m-1])<0
K<(a[m]+a[m-1])/2  => K ki max value
*/

#include<bits\stdc++.h>
#include<climits>
using namespace std;

float max(float a,float b){
    if(a>=b) return a;
    else return b;
}

float min(float a,float b){
    if(a<=b) return a;
    else return b;
}

int main(){
    int arr[]={5,3,10,3};
    int n=4;
    float Kmin=float(INT_MIN);
    float Kmax=float(INT_MAX);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bool flag=true; //means K ki value possible h
    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            Kmin=max(Kmin,(arr[i]+arr[i+1])/2.0);
        }
        else{
            Kmax=min(Kmax,(arr[i]+arr[i+1])/2.0);
        }

        if(Kmin>Kmax){
            flag=false;
            break;
        }
    }
    if(flag==false) cout<<"-1";
    else if(Kmin==Kmax){
        //Kmin and Kmax are integers
        if(Kmin-int(Kmin)==0){
            cout<<"There is one value of K as "<<Kmin;
        }
        else{
            cout<<"-1";
        }
    }
    else{
        //checking that Kmin is integer or float
        if(Kmin-int(Kmin)>0){
            Kmin=int(Kmin)+1;
        }
        cout<<"The range of K is :["<<Kmin<<" to "<<int(Kmax)<<"]";
    }
}

/*
Test case-
5 3 6 10
5 3 7
5 3 10
5 3 8
*/