// First negative number in every window of size K

#include<iostream>
#include<vector>
using namespace std;

// 2 -3 4 4 -7 -1 4 -2 6
// -3 -3 -7 -7 -7 -1 -2
// for k=3


vector<int> method1(vector<int> &v,int k){
    int n=v.size();
    vector<int> ans;
    for(int i=0;i<n-k+1;i++){
        for(int j=i;j<i+k;j++){
            if(v[j]<0){
                ans.push_back(v[j]);
                break;
            }
        }
    }
    return ans;
}

vector<int> method2(vector<int> &v,int k){
    int n=v.size();
    vector<int> ans(n-k+1,0);
    int negIdx=-1;
    // first negative element index for first window of size k
    for(int i=0;i<k;i++){
        if(v[i]<0){
            negIdx=i;
            break;
        }
    }  
    if(negIdx==-1) ans[0]=1;
    else ans[0]=v[negIdx];
    int i=1;
    int j=k;
    while(j<n){
        if(negIdx>=i) ans[i]=v[negIdx];
        else{
            negIdx=-1;
            for(int x=i;x<=j;x++){  // ye har samey nhi chal rha negIdx->0,0+k,0+2k aise chal rha h
                if(v[x]<0){
                    negIdx=x;
                    break;
                }
            }
            if(negIdx!=-1) ans[i]=v[negIdx];
            else ans[i]=1;
        }
        i++;
        j++;
    }
    return ans;
}

int main(){
    vector<int> arr={2,-3, 4,4,-7, -1,4,-2, 6};
    int k=3;
    vector<int> ans=method2(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}