class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ne=0;
        int p=nums[n-1]*nums[n-2]*nums[n-3];
        if(nums[0]<0 && nums[1]<0)ne=nums[0]*nums[1]*nums[n-1];
        return max(ne,p);
    }
};