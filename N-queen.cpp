#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

bool isSafe(vector<vector<int>> b, int row,int col,int n){
    for(int j=0;j<n;j++){
        if(b[row][j] == 1 && j!= col) return false;        
    }
    for(int i=0;i<n;i++){
        if(b[i][col]==1 && i!= row) return false ;        
    }

    for(int i=0,j=0;i<n;i++,j++)
        if(b[i][j]==1 && i!=row && j!=col) return false;    
    
    return true;
}

bool nqueen(vector<vector<int>> b,int col ,int n){    
    if(col == n){       
        // cout<<"Enterd base case"<<endl;
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.clear();
            for(int j=0;j<n;j++){
                temp.push_back(b[i][j]);
            }
            ans.push_back(temp);
            
        }
        
        // cout<<"completed"<<endl;
        return true;
    }
    
    for(int row =0;row <n;row++){
        // cout<<"Enterd for loop"<<endl;
        if(isSafe(b,row,col,n)){
            b[row][col]=1;
            if(nqueen(b,col+1,n))
                return true;
            b[row][col]=0;                        
        }
    }
    return false;


}

int main(){
    cout<<"Enter size of board: ";
    int n;cin>>n;
    vector<vector<int>> b( n , vector<int> (n, 0));
    nqueen(b,0,n);
    cout<<"Returned from nqueen"<<endl;
    vector<pair<int,int>> sol;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<ans[i][j]<<"  ";
            }
            cout<<endl;
            
        }
        // for(int i=0;i<n;i++)
        //     cout<<sol[i].first<<"   "<<sol[i].second<<endl;

            
    



}