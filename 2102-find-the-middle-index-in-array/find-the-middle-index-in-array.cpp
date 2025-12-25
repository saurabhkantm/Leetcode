class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
       int left=0;
       int middle=0;
       for(auto x:nums)
        middle+=x;
      for(int i=0;i<nums.size();i++){
        int right=middle-left-nums[i];

      if(left==right)
       return i;
     left+=nums[i];
      }
    return -1;  
    }
};