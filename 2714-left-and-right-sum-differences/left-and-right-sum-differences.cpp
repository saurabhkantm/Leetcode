class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        int i=0, totalsum=0, leftsum=0; 
        vector<int>left, right;
        for(int i=0; i<n; i++){
            totalsum+=nums[i];
        }
        vector<int>r(n);
        while(i<n){
            int rightsum= totalsum-leftsum-nums[i];
            r[i]= abs(leftsum-rightsum);
            leftsum+=nums[i];
            i++;
        }
        return r;
    }
};