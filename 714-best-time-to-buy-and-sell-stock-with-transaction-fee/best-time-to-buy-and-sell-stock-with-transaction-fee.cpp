class Solution {
public:
int solve(int i,bool buy ,vector<int>& prices,int fee, vector<vector<int>>&dp){
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][buy]!=-1) return dp[i][buy];
    int nottake=0,take=0;
    nottake=solve(i+1,buy,prices,fee,dp);
    if(buy==0){
        take=solve(i+1,1,prices,fee,dp)-prices[i];
    }
    else{
        take=solve(i+1,0,prices,fee,dp)+prices[i]-fee;
    }
    return dp[i][buy]=max(take,nottake);
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,prices,fee,dp);
    }
};