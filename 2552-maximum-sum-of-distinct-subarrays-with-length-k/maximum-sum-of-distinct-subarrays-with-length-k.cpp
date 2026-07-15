class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        long long csum=0,sum=0;
        int n=nums.size();
        map<int,int>m;
        while(j<n){
            sum+=nums[j];
            m[nums[j]]++;
            if(j-i+1==k){
                if(m.size()==k){
                    csum=max(csum,sum);
                }
            sum-=nums[i];
            m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
            i++;
        }
        j++;
        }
        return csum;
    }
};