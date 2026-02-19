class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, n = s.size();
        int i = 0, cnt0 = 0, cnt1 = 0;

        while(i<n){
            while(i<n && s[i] == '0'){
                cnt0++;
                i++;
            }

            ans += min(cnt0, cnt1);
            cnt1 = 0;   
            
            while(i<n && s[i] == '1'){
                cnt1++;
                i++;
            }

            ans += min(cnt0, cnt1);
            cnt0 = 0;
            
        }

        return ans;
    }
};