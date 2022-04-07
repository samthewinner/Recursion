#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void f(string s,string ans,int i){
    if(i==s.length()){
        if(ans=="") cout<<"NULL";
        else cout<<ans<<"\n";
        return;
    }
    
    ans+=s[i];
    f(s,ans,i+1);
    
    f(s,ans.substr(0,ans.length()-1),i+1);
}
    

int main()
{
    string s ;
    getline (cin, s);
    cout<<"Substrings are:"<<endl;
    f(s,"",0);
    
    

    return 0;
}
