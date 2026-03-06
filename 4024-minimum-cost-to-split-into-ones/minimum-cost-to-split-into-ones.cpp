class Solution {
public:
    int minCost(int n) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 0;
        for (int x = 2; x <= n; x++) {
            dp[x] = LLONG_MAX;
            for (int a = 1; a < x; a++) {
                long long cost = 1LL * a * (x - a) + dp[a] + dp[x - a];
                dp[x] = min(dp[x], cost);
            }
        }
        return dp[n];
    }
};