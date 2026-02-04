class Solution {
public:
int solve(int idx,bool buy,vector<int>&prices,vector<vector<int>>&dp){
       //base
       if(idx>=prices.size()) return 0;
   if(dp[idx][buy]!=-1) return dp[idx][buy];
   //nottake
   int nottake=solve(idx+1,buy,prices,dp);
   //take
   int take=0;
   if(!buy){
   take=-prices[idx]+solve(idx+1,1,prices,dp);
   }
   else{
    take=prices[idx]+solve(idx+1,0,prices,dp);
   }
   return dp[idx][buy]=max(take,nottake);
}
    int maxProfit(vector<int>& prices) {
   int n=prices.size();
   vector<vector<int>>dp(n,vector<int>(2,-1));
   return solve(0,0,prices,dp);
    }
};
