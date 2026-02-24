class Solution {
public:
int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i==j){
            return nums[i];
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take1 = nums[i] + min(solve(nums,i+2,j,dp),solve(nums,i+1,j-1,dp));
        int take2 = nums[j] + min(solve(nums,i+1,j-1,dp),solve(nums,i,j-2,dp));

        return dp[i][j] = max(take1,take2);
    }
    bool stoneGame(vector<int>& piles) {
         int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int first = solve(piles,0,n-1,dp);
        int sum = 0;
        // cout<<first<<endl;
        for(int i=0;i<piles.size();i++){
            sum += piles[i];
        }
        int second = sum - first;
        // cout<<second<<endl;
        if(first>=second){
            return true;
        }
        return false;
    }
};