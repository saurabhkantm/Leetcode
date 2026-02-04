class Solution {
public:
int solve(int i,vector<int>&nums,vector<int>&dp){
    //base case 
    if(i>=nums.size())
    return 0;
    if(dp[i]!=-1) return dp[i];
    //pick
     int pick=nums[i]+solve(i+2,nums,dp);
    //not pick
    int notpick= solve(i+1,nums,dp);
    return dp[i]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};
//1,2,3,1
//pick: 1+3
//notpick:2+1
//mx(4,3)=4