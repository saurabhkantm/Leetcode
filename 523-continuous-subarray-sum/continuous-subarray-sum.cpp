class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int x = prefix % k;

            if (mp.count(x)) {
                if (i - mp[x] >= 2) return true;
            } else {
                mp[x] = i;
            }
        }
        return false;
    }
};
