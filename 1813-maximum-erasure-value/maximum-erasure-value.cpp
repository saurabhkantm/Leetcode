class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         map<int,int>m;
     int i=0,j=0,len=0,sum=0;
     while(j<nums.size()){
        len+=nums[j];
        m[nums[j]]++;
        while(m[nums[j]]>1){
            m[nums[i]]--;
             len-= nums[i];
            if(m[nums[i]]==0){
                m.erase(nums[i]);
        }
                i++;
        }
                sum=max(len,sum);
            j++;
     }
     return sum;
    }
};