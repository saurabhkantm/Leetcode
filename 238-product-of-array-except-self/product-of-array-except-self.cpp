class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        int left=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=left;
            left*=nums[i];
        }
        int r=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=r;
            r*=nums[i];
        } 
        return ans;  
    }
};