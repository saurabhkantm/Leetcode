class Solution {
public:
    int maxRob(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i > n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];

        return dp[i] = max(maxRob(i+1, n, nums, dp), (nums[i] + maxRob(i+2, n, nums, dp)));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0], nums[1]);

        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);
        return max(maxRob(0, n-2, nums, dp), maxRob(1, n-1, nums, dp2));
    }
};