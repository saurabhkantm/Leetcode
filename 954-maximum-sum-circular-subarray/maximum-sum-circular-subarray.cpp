class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int n=nums.size();
        // int ans=INT_MIN;
        // vector<int>arr(2*n);
        // for(int i=0;i<n;i++){
        //  arr[i]=nums[i];
        //  arr[i+n]=nums[i];
        // }
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=0;j<n;j++){
        //     sum+=arr[i+j];
        //     ans=max(ans,sum);
        // }
        // }
        // return ans;
        int n=nums.size();
        int currmax=0,maxi=INT_MIN;
        int currmin=0,mini=INT_MAX;
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
            //calculate max first
            currmax=max(currmax+nums[i],nums[i]);
            maxi=max(currmax,maxi);
            //calculate min first
            currmin=min(currmin+nums[i],nums[i]);
            mini=min(currmin,mini);
        }
            if(maxi<0) return maxi;;
        return max(maxi,total_sum-mini);
    }
};