class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums.back();

        int k = 0;
        vector<int> result;

        for(int i = min; i < max; i++)  {
            if(i == nums[k]) {
                k++;
            } else {
                result.push_back(i);
            }
        }

        return result;
    }
};