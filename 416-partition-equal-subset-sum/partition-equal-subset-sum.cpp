class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)
        return false;
        int target=sum/2;
        vector<int>dp(target+1,false);
        dp[0] = true; 
        for(int i = 0; i < n; i++){
            int num = nums[i];
            // Update dp array backwards
            for(int j = target; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};