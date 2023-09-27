// Second largest element in the array

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr1[7]={1,2,5,18,9,4,6};

    cout<<"--------Array--------"<<endl;
    for(int i=0;i<7;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;


    cout<<"--------Method 1--------"<<endl;
    int max1=INT_MIN;
    for(int i=0;i<7;i++){
        if(max1<arr1[i]) max1=arr1[i];
    }
    int smax1=INT_MIN;
    for(int i=0;i<7;i++){
        if(smax1<arr1[i] && arr1[i]!=max1) smax1=arr1[i];
    }
    cout<<"Maximum : "<<max1<<endl;
    cout<<"Second maximum : "<<smax1<<endl;
    
    
    cout<<"--------Method 2--------"<<endl;
    int max2=INT_MIN;
    for(int i=0;i<7;i++){
        if(max2<arr1[i]) max2=arr1[i];
    }
    for(int i=0;i<7;i++){
        if(arr1[i]==max2) arr1[i]=INT_MIN;
    }
    int smax2=INT_MIN;
    for(int i=0;i<7;i++){
        if(smax2<arr1[i]) smax2=arr1[i];
    }
    cout<<"Maximum : "<<max2<<endl;
    cout<<"Second maximum : "<<smax2<<endl;
}