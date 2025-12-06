class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0); //number of ways to partition first r elements.
        vector<int> ps(n + 1, 0); // prefix sum of dp.
        dp[0] = ps[0] = 1;

        multiset<int> st; // to get the min and max element in log(n)

        for(int l = 0, r = 1; r <= n; r++) {
            st.insert(nums[r - 1]);

            // shrink window
            while(*st.rbegin() - *st.begin() > k) {
                st.erase(st.find(nums[l]));
                l++;
            } 

            int prev = (l > 0) ? ps[l - 1] : 0;
            dp[r] = (ps[r - 1] - prev + MOD) % MOD;
            ps[r] = (ps[r - 1] + dp[r]) % MOD;
        }

        return dp[n];
    }
};