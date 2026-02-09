class Solution {
public:
long long solve(int indx,vector<int>&nums,bool flag,vector<vector<long long>>&dp){
    //base case 
    if(indx>=nums.size()) return 0;
    if(dp[indx][flag]!=-1) return dp[indx][flag];
    //not take
    long long nottake=solve(indx+1,nums,flag,dp);
    //take
    long long take;
    if(!flag){
        take=solve(indx+1,nums,true,dp)+nums[indx];
    }
    else{
        take=solve(indx+1,nums,false,dp)-nums[indx];
    }
    return dp[indx][flag]=max(take,nottake);
}
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long >(2,-1));
       return solve(0,nums,false,dp); 
    }
};