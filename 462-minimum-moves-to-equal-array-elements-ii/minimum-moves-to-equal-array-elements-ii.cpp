class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int i=0,j=n-1;
        while(i<j){
       count+=nums[j]-nums[i];
       i++;
       j--;
        }
        return count;
    }
};