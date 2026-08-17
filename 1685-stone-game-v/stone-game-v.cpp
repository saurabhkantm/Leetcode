class Solution {
    
    vector<int> prefix;
    vector<vector<int>> dp;

public:

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
    int solve(int left, int right) {
        // Only one stone remains
        if (left == right) {
            return 0;
        }
        // Return already calculated result
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int ans = 0;
        // Try every possible split
        for (int i = left; i < right; i++) {
            // Calculate left and right sums using Prefix Sum
            int leftSum = prefix[i + 1] - prefix[left];
            int rightSum = prefix[right + 1] - prefix[i + 1];
            // Left side is smaller
            if (leftSum < rightSum) {
                ans = max(
                    ans,
                    leftSum + solve(left, i)
                );
            }
            // Right side is smaller
            else if (rightSum < leftSum) {
                ans = max(
                    ans,
                    rightSum + solve(i + 1, right)
                );
            }
            // Both sides have equal sum
            else {
               ans = max(
                    ans,
                    max(
                      leftSum + solve(left, i),
                        rightSum + solve(i + 1, right)
                    )
                );
            }
        }
        // Store the answer for this range
        dp[left][right] = ans;
        return ans;
    }
};
