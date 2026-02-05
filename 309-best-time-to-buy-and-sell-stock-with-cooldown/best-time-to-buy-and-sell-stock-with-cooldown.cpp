class Solution {
public:
int solve(int i,bool isbuy,vector<int>& prices, vector<vector<int>>&dp){
    //base
    if(i>=prices.size()) return 0;
    if(dp[i][isbuy]!=-1) return dp[i][isbuy];
    //not take
    int nottake=solve(i+1,isbuy,prices,dp);
    //take
    int take=0;
    if(isbuy==false){
        take=-prices[i]+solve(i+1,true,prices,dp);
    }
    else{
        take=prices[i]+solve(i+2,false,prices,dp);
    }
    return dp[i][isbuy]=max(take,nottake);
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,false,prices,dp);
    }
};

