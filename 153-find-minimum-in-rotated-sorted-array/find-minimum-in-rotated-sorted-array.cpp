class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int ans=nums[0];
        while(l<h){
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[h]){
                l=mid+1;
            }
            else{
                ans=nums[mid];
                h=mid;//move toward left side
            }
        }
        return nums[h];
    }
};