class Solution {
public:
int solve(int idx,bool isbuy,vector<int>& prices,int k, vector<vector<vector<int>>>&dp){
    //base case
  if(idx>=prices.size())
  return 0;
  if(dp[idx][isbuy][k]!=-1) return dp[idx][isbuy][k];
    //nottake
    int nottake=solve(idx+1,isbuy,prices,k,dp);
    //take
    int take=0;
    if(k>0){
        if(isbuy==false){
            take=-prices[idx]+solve(idx+1,true,prices,k,dp);
        }
        else{
            take=prices[idx]+solve(idx+1,false,prices,k-1,dp);
        }
    }
    return dp[idx][isbuy][k]=max(take,nottake);
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,false,prices,k,dp);
    }
};
