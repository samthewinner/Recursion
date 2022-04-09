#include <bits/stdc++.h>

using namespace std;

void f(vector<int> a,vector<int> v, vector<vector<int>> &fans,int idx,int t){
        if(t<0 || idx == a.size()) return ;
        if(t==0) {
            fans.push_back(v);
            return ;
        }
        v.push_back(a[idx]);
        f(a,v,fans,idx,t-a[idx]);
        v.pop_back();
        f(a,v,fans,idx+1,t);
        
    }
 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> fans;
        vector<int> v;
        f(candidates,v,fans, 0,target);
        return fans;
    }

int main(){
  vector<int> v;
  cout<<"Enter no. of elements:  ";
  int n;cin>>n;
  cout<<"Enter elements of array\n";
  
  for(int i=0;i<n;i++){
    int a;cin>>a;
    v.push_back(a);
  }
  cout<<"Enter target value: ";
  int target;cin>>target;
  vector<vector<int>> ans;
  ans = combinationSum(v,target);
  
  for(auto it: ans){
    for(auto j: it)
        cout<<j;
    cout<<endl;
  }
  return 0;
}
