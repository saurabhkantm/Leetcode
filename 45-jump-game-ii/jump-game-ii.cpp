class Solution {
public:
 int solve(int i,vector<int>& nums, vector<int>&dp){
   if(i>=nums.size()-1)
   return 0;
   if(nums[i]==0) return INT_MAX/2;
   if(dp[i]!=-1) return dp[i];
   int ans = INT_MAX;
   for(int idx=i+1;idx<=i+nums[i];idx++){
        int take = 1 + solve(idx,nums,dp);
        ans = min(ans,take);
   }
   return dp[i]=ans;

 }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};