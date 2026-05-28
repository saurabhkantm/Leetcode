class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        long long sum=0,cmax=0;
        map<int,int>m;
        int n=nums.size();
        while(j<n){
       sum+=nums[j];
       m[nums[j]]++;
        if(j-i+1==k){
            if(m.size()==k){
               cmax=max(cmax,sum);
            }
             sum-=nums[i];
               m[nums[i]]--;
               if(m[nums[i]]==0) m.erase(nums[i]);
               i++;
            }
            j++;
        }
        return cmax;
    }
};