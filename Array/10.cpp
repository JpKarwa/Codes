// Move all the negative number to end and positive to beginning with constant extra space

#include<iostream>
#include<vector>
using namespace std;

void sort1(vector<int> &v){
    // Two pointer approach
    int i=0;
    int j=v.size()-1;

    while(i<j){

        if(v[i]<0 && v[j]>0){
            //swap the elements
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }

        if(v[i]>0) i++;
        if(v[j]<1) j--;
    }

    // Ise shi krne ke liye 3 trike h
    // ELSE IF ka use krke
    // First two condition ke ek condition if(i>j) break;
    // Last wali condition ko sbse pehle check kro
}


int main(){
    vector<int> v1={1,-2,3,-4,-5,6,-7,8};
    sort1(v1);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}