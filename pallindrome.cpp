#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool f(string s,int i){
    if(i>=s.length() /2 ) return true;
    
    return  s[i]==s[s.length()-i-1] &&  f(s,i+1) ;
}

int main()
{
    string s ;
    getline (cin, s);
    
    cout<<f(s,0);
    

    return 0;
}
