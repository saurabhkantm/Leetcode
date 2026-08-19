class Solution {
public:
int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
    //base case 
    if(i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MIN;
    for(int k=i+1;k<j;k++){
      int cost=solve(i,k,nums,dp)+solve(k,j,nums,dp)+nums[i]*nums[k]*nums[j];
      ans=max(ans,cost);
    }
    return dp[i][j]=ans;
}
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,nums,dp);
    }
};