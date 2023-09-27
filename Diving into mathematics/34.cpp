// print factorial of first 25 natural number and modulo the result by 10^9+7;

#include<iostream>
#include<vector>
using namespace std;

vector<long long int> factorial(int n){
    vector<long long int> fact(n+1,1);
    int c=1000000000+7;
    for(int i=2;i<=n;i++){
        fact[i]=(i%(c)*fact[i-1]%c)%c;
    }
    return fact;
}

int main(){
    int n=25;
    vector<long long int> ans=factorial(n);
    for(int i=0;i<ans.size();i++){
        cout<<i<<"!="<<ans[i]<<endl;
    }
}