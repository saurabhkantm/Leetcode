class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int i, string &s) {
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        int single = 0;
        single += solve(i + 1, s);

        int pair = 0;
        if(i + 1 < n && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6'))) pair += solve(i + 2, s);

        return dp[i] = single + pair;
    }

    int numDecodings(string s) {
        n = s.size();
        dp.resize(n, -1);
        return solve(0, s);
    }
};