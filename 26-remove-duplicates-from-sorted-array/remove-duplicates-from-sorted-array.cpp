class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[j-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};

//nums = [1,1,2]
//[1,2] 2
// nums = [0,0,1,1,1,2,2,3,3,4]
//[0,1,2,3,4]= 5k=5