class Solution {
public:
    int solve(vector<int>&prices,bool buy,int left,int i,vector<vector<vector<int>>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][left][buy]!=-1){
            return dp[i][left][buy];
        }
        int notTake = solve(prices,buy,left,i+1,dp);
        int take = 0;
        if(left>0){
            if(buy){
                take = prices[i] + solve(prices,false,left-1,i+1,dp);
            }
            else{
                take = -prices[i] + solve(prices,true,left,i+1,dp);
            }
        }
        return dp[i][left][buy] = max(take,notTake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(prices,false,2,0,dp);
       
    }
};