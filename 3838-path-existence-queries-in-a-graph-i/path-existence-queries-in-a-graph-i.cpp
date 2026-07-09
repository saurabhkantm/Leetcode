class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<bool> ans(m);
        vector<int> comp(n, 0);
        
        for(int i=1;i<n;i++){
            if(abs(nums[i] - nums[i-1]) <= maxDiff){
                comp[i] = comp[i-1];
            }
            else{
                comp[i] = comp[i-1] + 1;
            }
        }

        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];

            int cmp1 = comp[l];
            int cmp2 = comp[r];

            ans[i] = (cmp1 == cmp2);
        }

        return ans;
    }
};