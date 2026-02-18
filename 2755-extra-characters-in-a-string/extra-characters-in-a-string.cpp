class Solution {
   
    int n;
    int dp[51];

    int fn(int i,string s,vector<string>& d){

        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        int mini=1+fn(i+1,s,d);
        for(auto word:d){
            if(s.substr(i,word.length())==word){
                mini=min(mini,fn(i+word.length(),s,d));
            }
        }
        
        return dp[i] = mini;
    }
public:
    int minExtraChar(string s, vector<string>& d) {
        
        n=s.length();
        memset(dp,-1,sizeof(dp));
        return fn(0,s,d);
    }
};