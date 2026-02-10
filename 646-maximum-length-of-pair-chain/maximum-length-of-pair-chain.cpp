class Solution {
public:
int solve(int i,vector<vector<int>>&pairs,int prev,vector<vector<int>>&dp){
    if(i>=pairs.size()) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //nottake
    int nottake=solve(i+1,pairs,prev,dp);
    //take
    int take=0;
    if(prev==-1||pairs[prev][1]<pairs[i][0]){
        take=1+solve(i+1,pairs,i,dp);
    }
    return dp[i][prev+1]=max(take,nottake);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,pairs,-1,dp);
    }
};