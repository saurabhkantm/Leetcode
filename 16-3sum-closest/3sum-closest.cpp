class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int diff=INT_MAX;
        for(int i=0;i<n-2;i++){
            int first=nums[i];
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum==target)
                return target;
             if(abs(sum-target)<diff){
                  diff=abs(sum-target);
                  ans=sum;
            }
                if(sum<target)
                    start++;
                else
                    end--;
            }
        }
        return ans;
    }
};
// while(start<end)
//ums = [-1,2,1,-4], target = 1
// sort:[-4,-1,1,2]   diff=-1, ans=0

// nums[0]=-4
// start=-1   diff=|-3-1|=4
// end=2           ans=-3
// -4-1+2=-3
// sum<target ->start++;

// nums[0]=-4
// start=1   diff=|-1-1|=2
// end=2           ans=-1            
// -4+1+2=-1
// sum<target->start++;

// nums[1]=-1
// start=1       diff=|2-1|=1
// end=2           ans=2
// -1+2+1=2