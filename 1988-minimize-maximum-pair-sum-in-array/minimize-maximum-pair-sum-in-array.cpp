class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        int max_sum=0;
        while(i<j){
            int sum=nums[i]+nums[j];
            max_sum=max(sum,max_sum);
            i++,j--;
        }
        return max_sum;
    }
};