class Solution {
public:
int solve(int i,bool buy,int k,vector<int>& prices, vector<vector<vector<int>>>&dp){
    if(i==prices.size()||k==0) return 0;
if(dp[i][buy][k]!=-1) 
return dp[i][buy][k];
int take=0,nottake=0;
nottake=solve(i+1,buy,k,prices,dp);
if(buy==0){
    take=solve(i+1,1,k,prices,dp)-prices[i];
}
else{
    take=solve(i+1,0,k-1,prices,dp)+prices[i];
}
return dp[i][buy][k]=max(take,nottake);
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(k+1,-1)));
       return solve(0,0,k,prices,dp); 
    }
};

