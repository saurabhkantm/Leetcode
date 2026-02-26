class Solution {
public:
    
    long long at(vector<int>& a, int k){
        unordered_map<int,int> f;
        int l = 0;
        long long cnt = 0;

        for(int r = 0; r < a.size(); r++){
            f[a[r]]++;

            while(f.size() > k){
                if(--f[a[l]] == 0)
                    f.erase(a[l]);
                l++;
            }

            cnt += (r - l + 1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return at(nums, k) - at(nums, k - 1);
    }
};