bool isValid(int h,int m){
        return h>=0 and h<=11 and m>=0 and m<=59;
    }
    
    void solve(vector<pair<int,int>>time,vector<string> &ans,pair<int,int>temp,int t,int idx){
//         base case:
        
        if(t==0){
            string h = to_string(temp.first);
            string m  =to_string(temp.second);
            string f = h+":";
            if(m.size() == 1) {
                m="0"+m;
                f+=m;
            }
            else f+=m;
            ans.push_back(f);
            return;
        }
        if(idx==time.size()) return;
//         body:
        
//      keep the bit as 0 and recursively call next
        solve(time,ans,temp,t,idx+1);
        
        int h = temp.first;
        int m = temp.second;
                
//         hour
        if(time[idx].first) h+=time[idx].second;
//         minute
        else m+=time[idx].second;

//        make the bit as 1 if it gives a valid time
        if(isValid(h,m)) {
            solve(time,ans,{h,m},t-1,idx+1);
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
//         true:hour
//         false:min
        vector<pair<int,int>>time ={{1,1},{1,2},{1,4},{1,8},
                                     {0,1},{0,2},{0,4},{0,8},{0,16},{0,32}
                                    };
        vector<string>ans;
        // if(turnedOn == 0 || turnedOn >=9) return ans;        
        solve(time,ans,{0,0},turnedOn,0);
        return ans;
        
    }
