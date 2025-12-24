class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        // every index of vector is a map which stores max length of subseq for each diff.
        vector<unordered_map<int, int>> dp(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];

                if(dp[j].count(diff)) dp[i][diff] = dp[j][diff] + 1;
                else dp[i][diff] = 2;
            }
        }

        // select max length
        int ans = 2;
        for(int i = 0; i < n; i++) {
            for(auto &it : dp[i]) {
                ans = max(ans, it.second);
            }
        }

        return ans;
    }
};