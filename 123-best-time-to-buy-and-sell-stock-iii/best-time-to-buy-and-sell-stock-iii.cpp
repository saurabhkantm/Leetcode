class Solution {
public:
int solve(int i,bool buy,int left,vector<int>& prices, vector<vector<vector<int>>>&dp){
    if(i==prices.size()||left==0){
        return 0;
    }
    if(dp[i][left][buy]!=-1) return dp[i][left][buy];
    int take=0,nottake=0;
    nottake=solve(i+1,buy,left,prices,dp);
    if(buy==0){
        //buy
        take=solve(i+1,1,left,prices,dp)-prices[i];
    }
    else{
        //sell
        take=solve(i+1,0,left-1,prices,dp)+prices[i];
    }
    return dp[i][left][buy]=max(take,nottake);
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(0,0,2,prices,dp);
    }
};