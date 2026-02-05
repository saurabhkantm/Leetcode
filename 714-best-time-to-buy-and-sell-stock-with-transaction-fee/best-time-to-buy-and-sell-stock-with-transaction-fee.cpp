class Solution {
public:
int solve(int i,bool isbuy,vector<int>& prices,int fee,vector<vector<int>>&dp){
    //base case
    if(i>=prices.size()) return 0;
    if(dp[i][isbuy]!=-1) return dp[i][isbuy];
    //nottake
    int nottake=solve(i+1,isbuy,prices,fee,dp);
    //take
    int take=0;
    if(isbuy==false){
        take=-prices[i]+solve(i+1,true,prices,fee,dp);
    }
    else{
        take=-fee+prices[i]+solve(i+1,false,prices,fee,dp);
    }
    return dp[i][isbuy]=max(take,nottake);
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,false,prices,fee,dp);
    }
};
