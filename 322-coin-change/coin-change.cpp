class Solution {
public:
int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
    //base case
    if(i>=coins.size()){
        if(amount==0)
            return 0;
        else
            return INT_MAX/2;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    //notpick
    int notpick=solve(coins,amount,i+1,dp);
    //pick
    int pick=INT_MAX/2;
    if(coins[i]<=amount){
     pick=solve(coins,amount-coins[i],i,dp)+1;
    }
    return dp[i][amount]=min(pick,notpick);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(coins,amount,0,dp);
        if(ans>=INT_MAX/2)
        return -1;
        return ans;
    }
};