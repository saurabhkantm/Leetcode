class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n, 0), suffix(n, 0);
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] | nums[i-1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i+1] | nums[i+1];

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long val = prefix[i] | ((long long)nums[i] << k) | suffix[i];
            ans = max(ans, val);
        }

        return ans;
    }
};