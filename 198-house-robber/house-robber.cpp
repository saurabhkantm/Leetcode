class Solution {
public:
int solve(int idx,vector<int>&nums,vector<int>&dp){
   // int n=nums.size();
    //base case
    if(idx>=nums.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    //not take
    int nottake=solve(idx+1,nums,dp);
    //take
    int take=nums[idx]+solve(idx+2,nums,dp);
    return dp[idx]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};