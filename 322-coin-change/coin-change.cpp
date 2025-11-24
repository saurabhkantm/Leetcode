class Solution {
public:
    int solve(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (amount < 0 || index == coins.size()) return 1e9;

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int pick = 1e9, NotPick = 1e9;

        if (coins[index] <= amount) {
            pick = 1 + solve(index, coins, amount - coins[index], dp);
        }

        NotPick = solve(index + 1, coins, amount, dp);

        return dp[index][amount] = min(pick, NotPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, amount, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};
