class Solution {
public:
void allsubset(int idx,vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums){
    if(idx==nums.size()){
        ans.push_back(curr);
        return;
    }
    //pick
    curr.push_back(nums[idx]);
    allsubset(idx+1,ans,curr,nums);
    //not pick
    curr.pop_back();
    allsubset(idx+1,ans,curr,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        allsubset(0,ans,curr,nums);
        return ans;
    }
};