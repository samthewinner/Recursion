#include <iostream>
#include <bits/stdc++.h>
#include <ios>
using namespace std;

int m =0;
void f(vector<int> a,vector<int> &v,int k,int i,int sum){
  
    if(sum>k || i>a.size())
        return;
    if(sum==k){
        cout<<"{";
        for(auto it : v)
            cout<<it<<",";
            cout<<"\b";
        cout<<"}"<<endl;
        return;
    }
    
    v.push_back(a[i]);
    sum+=a[i];
    f(a,v,k,i+1,sum);
    v.pop_back();
    sum-=a[i];
    f(a,v,k,i+1,sum);
}

int main(){
    vector<int> v;
    cout<<"Enter no. of elements in array: ";
    int n;cin>>n;
    cout<<"Enter k: ";
    int k;cin>>k;
    
    cout<<"Enter elements of array: \n";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
   
    vector <int> ans;
    cout<<"Ans is :\n";
    f(v,ans,k,0,0);
}
