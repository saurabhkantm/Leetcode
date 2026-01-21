class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int total=INT_MAX,sum=0;
        while(r<nums.size()){
         sum+=nums[r];
         while(sum>=target){
         total=min(total,r-l+1);
         sum=sum-nums[l];
         l++;
        }
        r++;
        }
        return total==INT_MAX?0:total;
    }

};