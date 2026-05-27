class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>m;
       long long sum=0,maxsum=0,i=0,j=0;
        while(j<n){
            sum+=nums[j];
            m[nums[j]]++;
            if(j-i+1==k){
                if(m.size()==k){
                    maxsum=max(maxsum,sum);
                }
            sum-=nums[i];
            m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
            i++;
            }
        j++;
        }
        return maxsum;
    }
};