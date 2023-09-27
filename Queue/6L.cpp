// LEETCODE 1700 -> Number of students unable to eat lunch
// count hamara dekhe ja rha h contuously hamari cheeze kaise ho rhi h 
#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int countStudents(vector<int> &students,vector<int> &sandwiches){
    queue<int> q;
    for(auto itr:students){
        q.push(itr);
    }
    int i=0;
    int count=0;
    while(q.size()>0 && count!=q.size()){
        if(q.front()==sandwiches[i]){
            i++;
            q.pop();
            count=0;
        }
        else{
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();
}

int countStudents1(vector<int> &students,vector<int> &sandwiches){
    int n=students.size();
    int count=0;
    int i=0;
    while(students.size()){
        if(students[0]==sandwiches[0]){
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
            count=0;
        }
        else{
            if(count>students.size()-1) break;
            int x=students[0];
            students.erase(students.begin());
            students.push_back(x);
            count++;
        }
    }
    return students.size();
}

int main(){
    vector<int> preferences={1,1,0,0};
    vector<int> lunch={0,1,0,1};
    cout<<countStudents(preferences,lunch);
    cout<<countStudents1(preferences,lunch);
}