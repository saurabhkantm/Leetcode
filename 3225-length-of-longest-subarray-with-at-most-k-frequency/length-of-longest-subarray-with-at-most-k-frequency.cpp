class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //CODE
        int maxCnt = 1;
        unordered_map<int, int>freq;
        int i = 0;
        int j = 0;
        while(j < nums.size()){
            freq[nums[j]]++;
            if(freq[nums[j]] <= k){
                maxCnt = max(maxCnt, j - i + 1);
            }
            else{
                while(freq[nums[j]] > k && i < j){
                    freq[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        return maxCnt;
    }
};