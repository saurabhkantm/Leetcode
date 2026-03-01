class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxOnes = INT_MIN;
        int currOnes = 0;
        int left = 0;
        for(int right=0; right<n; right++){
            if(nums[right] == 1) currOnes++;
            while((right - left + 1) - currOnes > k){
                if(nums[left] == 1) currOnes--;
                left++;
            }
            maxOnes = max(maxOnes, right-left+1);
        }
        return maxOnes;
    }
};