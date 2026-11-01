class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0; i <= n-2; i += 2) {
            string str = to_string(nums[i]) + to_string(nums[i+1]);
            int num = stoi(str);
            ans = min(ans, num);
        }

        return ans;
    }
};