class Solution {
public:
    long long solve(int i, vector<int>& stoneValue, vector<long long>& dp) {
        if (i >= stoneValue.size()) return 0;
        if (dp[i] != -1) return dp[i];
        long long ans = LLONG_MIN;
        ans = max(ans, (long long)stoneValue[i] - solve(i + 1, stoneValue, dp));
        if (i + 1 < stoneValue.size()) {
            ans = max(ans, (long long)stoneValue[i] + stoneValue[i + 1] 
                      - solve(i + 2, stoneValue, dp));
        }
        if (i + 2 < stoneValue.size()) {
            ans = max(ans, (long long)stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] 
                      - solve(i + 3, stoneValue, dp));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<long long> dp(stoneValue.size(), -1);
        long long ans = solve(0, stoneValue, dp);
        if (ans > 0) return "Alice";
        if (ans < 0) return "Bob";
        return "Tie";
    }
};