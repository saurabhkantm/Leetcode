class Solution {
public:
    int numOfWays(int n) {
        long long x = 6;
        long long y = 6;
        int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            long long new_x = (x * 3 + y * 2) % mod;
            long long new_y = (x * 2 + y * 2) % mod;
            x = new_x;
            y = new_y;
        }
        return (x + y) % mod;
    }
};