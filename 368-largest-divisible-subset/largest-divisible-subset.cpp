class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> lis(n, 1), parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        int maxl = 1, maxindex = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if(lis[i] > maxl) {
                maxl = lis[i];
                maxindex = i;
            }
        }
       vector<int> ans;
        while(parent[maxindex] != maxindex) {
            ans.push_back(nums[maxindex]);
            maxindex = parent[maxindex];
        }
        ans.push_back(nums[maxindex]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
