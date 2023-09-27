/*
Check the array is almost sorted
(elements are at most one position away)
*/

#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"-----------------Method 1-----------------";
    vector<int> brr(n,0);
    brr=arr;
    //sort the array
    for(int i=0;i<n-1;i++){
        bool swapping=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapping=true;
            }
        }
        if(swapping=false){
            break;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    bool almostSorted=true;     //pehle mark krke chalta hu ki almostSorted h
    for(int i=0;i<n;i++){
        if(i==0 && brr[i]!=arr[i] && brr[i]!=arr[i+1]){
            almostSorted=false;
            break;
        }
        else if(i==n-1 && brr[i]!=arr[i] && brr[i]!=arr[i-1]){
            almostSorted=false;
            break;
        }
        else if(brr[i]!=arr[i] && brr[i]!=arr[i-1] && brr[i]!=arr[i+1]){
            almostSorted=false;
            break;
        }
    }
    cout<<endl;
    cout<<almostSorted<<endl;


    // TC-> O(n square)
    // SC-> O(n)

    cout<<"-----------------Method 2-----------------"<<endl;

    //har ek elment uthaya aur count no. of elements jo usse bade h ya barabar baki array me
    //actual position of that element = total elements-no. of elements greater than that element - 1
    //actual position - current position ka difference 0 ya 1 aata h toh almost sorted
    int crr[5]={4,2,9,7,8};

    bool almostSort=true;
    for(int i=0;i<n;i++){
        int maxCount=0;
        for(int j=0;j<n;j++){
            // if(i==j) continue;
            if(crr[j]>crr[i]){
                maxCount++;
            }
        }
        int actualIdx=n-maxCount-1;
        int diff=abs(actualIdx-i);
        if(diff>1){
            almostSort=false;
            break;
        }
        // if(actualIdx==0){
        //     if(crr[i]!=crr[actualIdx] && crr[i]!=crr[actualIdx+1]){
        //         almostSort=false;
        //         break;
        //     }
        // }
        // else if(actualIdx==n-1){
        //     if(crr[i]!=crr[actualIdx] && crr[i]!=crr[actualIdx-1]){
        //         almostSort=false;
        //         break;
        //     }
        // }
        // else {
        //     if(crr[i]!=crr[actualIdx] && crr[i]!=crr[actualIdx-1] && crr[i]!=crr[actualIdx+1]){
        //         almostSort=false;
        //         break;
        //     }
        // }
    }
    cout<<almostSort<<endl;

    //TC= O(n_square)
    //SC= O(1)

    cout<<"-----------------Method 3-----------------"<<endl;

    // if more than 1 swaps happen for one element it is not almost sorted
    //agar koi array almost sorted hota h toh vo ek hi pass me sort ho jata h
    int drr[5]={4,2,9,7,8};

    for(int i=0;i<n-1;i++){
        if(drr[i]>drr[i+1]){
            swap(drr[i],drr[i+1]);
            //agle wale se check hi na ho
            i++;
        }
    }
    //modified array
    for(int i=0;i<n;i++){
        cout<<drr[i]<<" ";
    }
    cout<<endl;
    //2 4 7 9 8 <- modified array

    //check if modified array is sorted
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(drr[i]>drr[i+1]){
            flag=false;
            break;
        }
    }
    if(flag==true) cout<<"Almost Sorted";
    else cout<<"Not almost sorted";

}