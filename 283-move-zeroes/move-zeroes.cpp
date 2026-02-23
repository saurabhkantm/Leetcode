class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int n=nums.size();
     int movezero=0;
     for(int i=0;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[movezero]);
            movezero++;
        }
     }   
    }
};

//nums = [0,1,0,3,12]
// i=0 0
// i=1 [1,0,0,3,12]
// i=2  0
// i=3  [1,3,0,0,12]
// i=4   [1,3,12,0,0]