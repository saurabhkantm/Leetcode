class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        sort(nums.begin(), nums.end());
        if(nums[n-1]!=nums[n-2]) return false;
        int num= n-1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] != num) return false;
            num--;
        }
        return true;
    }
};