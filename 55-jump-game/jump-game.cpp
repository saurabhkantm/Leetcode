class Solution {
public:
 bool solve(int i,vector<int>& nums, vector<int>&dp){
   if(i>=nums.size()-1)
   return true;
   if(nums[i]==0) return false;
   if(dp[i]!=-1) return dp[i];
   for(int idx=i+1;idx<=i+nums[i];idx++){
    if(solve(idx,nums,dp))
    return dp[i]=true;
   }
   return dp[i]=false;

 }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};