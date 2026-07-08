class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for(int i = 1; i <= n; i++){
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<int> cnt(n);
        vector<int> sum(n); 
        vector<long long> x(n); 
        cnt[0] = (s[0] != '0');
        sum[0] = s[0] - '0';
        x[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            cnt[i] = cnt[i - 1];
            if (digit != 0) cnt[i]++;
            sum[i] = sum[i - 1] + digit;
            x[i] = x[i - 1];
            if (digit != 0) x[i] = (x[i] * 10 + digit) % MOD;
        }
        vector<int> ans;
        for (auto &q : queries){
            int l = q[0];
            int r = q[1];
            int shift;
            if (l == 0) shift = cnt[r];
            else shift = cnt[r] - cnt[l - 1];
            long long digitSum;
            if (l == 0) digitSum = sum[r];
            else digitSum = sum[r] - sum[l - 1];
            long long number;
            if (l == 0) number = x[r];
            else  number = (x[r] - (x[l - 1] * pow10[shift]) % MOD + MOD) % MOD;
            ans.push_back((number * digitSum) % MOD);
        }
        return ans;
    }
};