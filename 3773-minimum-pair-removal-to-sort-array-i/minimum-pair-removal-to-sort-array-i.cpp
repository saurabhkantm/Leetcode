class Solution {
public:
    int n;
    bool isNonDecreasing(vector<int> &nums) {
        for(int i = 0; i < n-1; i++) {
            if(nums[i + 1] < nums[i]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        n = nums.size();
        int ans = 0;

        while(!isNonDecreasing(nums)) {
            int idx = 0;
            int min_sum = nums[0] + nums[1];
            
            for(int i = 1; i < n-1; i++) {
                int sum = nums[i] + nums[i + 1];
                if(sum < min_sum) {
                    min_sum = sum;
                    idx = i;
                }
            }

            nums[idx] = min_sum;
            nums.erase(nums.begin() + idx + 1);
            n = n - 1; // array size decreases by 1
            ans++;
        }

        return ans;
    }
};