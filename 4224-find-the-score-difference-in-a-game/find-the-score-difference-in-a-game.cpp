class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool flag = true;
        int score1 = 0, score2 = 0;
        for(int i=0;i<nums.size();i++){
            if((i+1) %6 == 0){
                flag = !flag;
            }
            if(nums[i] % 2 != 0){
                flag = !flag;
            }
            
            if(flag){
                score1 += nums[i];
            }
            else
                score2 += nums[i];
        }

        return score1 - score2;
    }
};