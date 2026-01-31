class Solution {
public:
    // s1-s2 = target
    // s2 = totalSum - s1
    // 2*s1 - totalSum = target
    // s1 = target + totalSum/2
    int solve(vector<int>&nums,int target,int i){
        if(i==nums.size()){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        // -neg
        int opt1 = solve(nums,target+nums[i],i+1);
        //pos
        int opt2 = 0;
        
        opt2 = solve(nums,target-nums[i],i+1);
        
        return opt1 + opt2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = solve(nums,target,0);
        return ans;

    }
};