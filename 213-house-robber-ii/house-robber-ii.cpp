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
        //base case
        if(n==1) return nums[0];
        vector<int>nums1;
        vector<int>nums2;
        for(int i=0;i<=n-2;i++){
        nums1.push_back(nums[i]);
        }
        for(int i=1;i<=n-1;i++){
        nums2.push_back(nums[i]);
        }
        int ans1= solve(0,nums1,dp);
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }
          int ans2=solve(0,nums2,dp);
          return max(ans1,ans2);
    }
};

