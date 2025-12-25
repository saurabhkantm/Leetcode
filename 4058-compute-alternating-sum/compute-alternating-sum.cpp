class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size();
        int ans,even=0,odd=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
           even+=nums[i];
            }
            else{
                odd+=nums[i];
            }
            ans=even-odd;
        }
        return ans;
    }
};