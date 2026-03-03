class Solution {
public:
    string invert(string &s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') ans += "1";
            else ans += "0";
        }

        return ans;
    }

    char findKthBit(int n, int k) {
        string ans = "0";

        for(int i = 0; i < n; i++) {
            string inverted = invert(ans);
            reverse(inverted.begin(), inverted.end());
            ans = ans + "1" + inverted;
        }

        return ans[k - 1];
    }
};