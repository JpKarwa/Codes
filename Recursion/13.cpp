// Find the subarrays of an array
// works only for unique elements

#include<bits\stdc++.h>
using namespace std;

void iterative(vector<int> arr,int n){
    for(int i=0;i<n;i++){      //start of subarray
        for(int j=i;j<n;j++){  //ending of subarray
            for(int k=i;k<=j;k++){  // for printing subarray from start to end
                cout<<arr[k];
            }
            cout<<endl;
        }
        
    }
}

void subarray(vector<int> org,vector<int> ans,int idx){
    //base case
    if(idx==org.size()){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    //calls
    subarray(org,ans,idx+1);
    if(ans.size()==0 || org[idx-1]==ans[ans.size()-1]){
        ans.push_back(org[idx]);
        subarray(org,ans,idx+1);
    }
}

int main(){
    vector<int> arr={1,2,3};
    // iterative(arr,4);
    vector<int> ans;
    subarray(arr,ans,0);
}