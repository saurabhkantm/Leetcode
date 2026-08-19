class Solution {
public:
int solve(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
    //base case
    if(i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        int cost=solve(i,k,cuts,dp)+solve(k,j,cuts,dp)+cuts[j]-cuts[i];
        ans=min(ans,cost);
    }
    return dp[i][j]=ans;
}
    int minCost(int n, vector<int>& cuts) {
        //code
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m=cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(0,m-1,cuts,dp);  
    }
};