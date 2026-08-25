class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mult = k;
        for(int x : nums){
            if(x == mult) mult += k;
        }
        return mult;
    }
};