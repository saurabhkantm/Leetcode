class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool all_zero = true;
        for(int i = 0; i < nums.size(); i++){
            total_xor ^= nums[i];
            if(nums[i] != 0) all_zero = false;
        }
        if(total_xor != 0) return nums.size();
        if(all_zero) return 0;
        return nums.size()-1;
    }
};