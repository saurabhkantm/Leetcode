class Solution {
public:
void removesubset(int idx,vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums){
    //all valid state
        ans.push_back(curr);
    for(int i=idx;i<nums.size();i++){
        if(i>idx&&(nums[i]==nums[i-1]))
        continue;
    curr.push_back(nums[i]);
    removesubset(i+1,ans,curr,nums);
    curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        removesubset(0,ans,curr,nums);
        return ans;
    }
};