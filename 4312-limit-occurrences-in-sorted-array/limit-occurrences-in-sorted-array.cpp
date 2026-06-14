class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ans.size()<k||ans[ans.size() - k] !=nums[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};