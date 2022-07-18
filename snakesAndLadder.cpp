pair<int,int> findcords(int val,int n){        
        int x = n-val/n -1;
        int y = val%n;
        if((n-1)%2 != x%2) y = n-y-1;
        return {x,y};
    }
    
    void solve(vector<vector<int>>& b,int n,int &ans,int steps,int x,int y){
        int val = (n-x-1)*n +y;
        if(val == n*n-1){
            ans = min(steps,ans);
            return;
        }
        for(int i=1;i<=6;i++){
            int num = val+i;
            pair<int,int>p = findcords(num,n);
            int nx = p.first;
            int ny = p.second;
            if(b[nx][ny] != -1) {
                num = b[nx][ny]-1;
                pair<int,int>p = findcords(num,n);
                nx = p.first;
                ny = p.second;                
            }
            solve(b,n,ans,steps+1,nx,ny);
        }
        return;
    }
    
    int snakesAndLadders(vector<vector<int>>& b) {
        int ans =INT_MAX;
        solve(b,b.size(),ans,0,b.size()-1,0);
        return ans;
    }
