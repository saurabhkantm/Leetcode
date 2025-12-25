class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        int ans = 0, cnt = 0;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int prev = INT_MIN;
        for(auto &it:m){
            if((prev == INT_MIN) || (it.first == prev+1)){
                cnt++;
                prev = it.first;
                ans = max(ans, cnt);
            }
            else{
                prev = it.first;
                cnt = 1;
            }
        }

        return ans;
    }
};