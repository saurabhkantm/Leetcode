class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int left = -1;
        int right = -1;
        int maxele = nums[0];
        int minele = nums[n-1];
        

        for(int i = 1; i < n; i++){
            maxele = max(maxele, nums[i]);
            if(nums[i] < maxele) right = i;
        }
        for(int i = n-2; i >= 0; i--){
            minele = min(minele, nums[i]);
            if(nums[i] > minele) left = i;
        }

        return (right==left) ? 0 : right-left + 1;


    }
};