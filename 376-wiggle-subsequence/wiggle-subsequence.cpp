class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         if(nums.size() < 2) return nums.size();
        int count=1;int dir=0;
        for(int i=1;i<nums.size();i++){
            int ans=nums[i-1]-nums[i];//differnce lena hai right-left
            if(ans>0&&dir<=0){
            count++;
            dir=1;//direction postive
        }
        else if(ans<0&& dir>=0){
            count++;
            dir=-1;//direction negative
        }
        }
        return count;
    }
};