class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //code
        int ans = 1;
        unordered_map<long long, int>mp;
        for(int num: nums) mp[num]++;
        if(mp.count(1)){
            int cnt = mp[1];
            if(cnt&1){
                ans = max(ans, cnt);
            }
            else ans = max(ans, cnt-1);
        }
        mp.erase(1);
        for(auto it: mp){
            long long val = it.first;
            int len = 0;
            
            while(mp.count(val) && mp[val] > 1){
                len+=2;
                if(val > INT_MAX) break;
                val *= val;
            }
            if(mp.count(val)) len++;
            else len--;
            ans = max(ans, len);
        }
        return ans;
    }
};