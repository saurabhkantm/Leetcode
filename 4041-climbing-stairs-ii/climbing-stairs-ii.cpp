class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==0) return 0;
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        int kel=n;
        for(int k=1;k<=n;k++){
            for(int jump=1;jump<=3;jump++){
                int prev=k-jump;
                if(prev>=0&&dp[prev]!=INT_MAX){
                    dp[k]=min(dp[k],dp[prev]+costs[k-1]+jump*jump);
                }
            }
        }
    return dp[n];
    }
};