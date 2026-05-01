class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long f0 = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            f0 += (long long)i * nums[i];
        }

        long long maxi = f0;
        long long prev = f0;

        for(int k = 1; k < n; k++){
            long long curr = prev + sum - (long long)n * nums[n - k];
            maxi = max(maxi, curr);
            prev = curr;
        }

        return maxi;
    }
};