class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        bool flag = 1;
        int prev = 0, cnt = 1;

        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]) return 0;
            if(flag){
                if(nums[i] > nums[i+1]){
                    if(i - prev == 0) return 0;
                    prev = i;
                    flag = 0;
                    cnt++;
                }
            }
            else{
                if(nums[i] < nums[i+1]){
                    if(i - prev == 0) return 0;
                    prev = i;
                    flag = 1;
                    cnt++;
                }
            }
        }

        return cnt == 3;
    }
};