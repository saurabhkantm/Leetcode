class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int cnt0 = 0;
        int cnt1 = 0;

        for (int i = 0; i < n; i++) {
            // pattern starts from 010101
            char char0 = (i % 2) + '0';
            // pattern starts from 101010
            char char1 = (1 - i % 2) + '0';

            if (s[i] != char0) {
                cnt0++;
            };
            if (s[i] != char1) {
                cnt1++;
            };
        }

        return min(cnt1, cnt0);
    }
};