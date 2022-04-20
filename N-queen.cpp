#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

bool isSafe(vector<vector<int>> b, int row,int col,int n){
    // check left row
    int j=col;
    while(j-- >= 0){
        if(b[row][j]==1 && j!=col) return false;
    }
    // check upward diagonal
    int i=row;
    j=col;
    while(j >= 0  && i>=0 ){
        if(b[i][j] ==1 && i!=row && j!=col) return false;
        i--;j--;
    }
    // check downward diagonal
    i=row;j=col;
    while(j<n && i < n) {
        if(b[i][j]==1 && i!=row && j!=col) return false;
        i++;j--;
    }
    
    
    
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
    // cout<<"Returned from nqueen"<<endl;
    // cout<<ans.empty()<<endl;
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
