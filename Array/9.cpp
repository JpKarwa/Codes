// Sort the array if 0's and 1's

#include<iostream>
#include<vector>
using namespace std;

void sort1(vector<int> &v){
    int n=v.size();
    int noz=0,noo=0;
    for(int i=0;i<n;i++){
        if(v[i]==0) noz++;
        else noo++;
    }
    //filling elements
    for(int i=0;i<n;i++){
        if(i<noz) v[i]=0;
        else v[i]=1;
    }
}

void sort2(vector<int> &v){
    // Two pointer approach
    int i=0;
    int j=v.size()-1;

    while(i<j){
        if(v[i]==0) i++;
        if(v[j]==1) j--;
        if(v[i]==1 && v[j]==0){
            v[i]=0;
            v[j]=1;
            // //swap the elements
            // int temp=v[i];
            // v[i]=v[j];
            // v[j]=temp;
            i++;
            j--;
        }

    }

    // Ise shi krne ke liye 3 trike h
    // ELSE IF ka use krke
    // First two condition ke ek condition if(i>j) break;
    // Last wali condition ko sbse pehle check kro
}


int main(){
    vector<int> v1={0,1,0,0,1,1,0,1};
    cout<<"--------Method 1--------"<<endl;
    sort1(v1);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    vector<int> v2={1,1,0,1,0,1,1,0};
    cout<<"--------Method 2--------"<<endl;
    sort2(v2);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
}