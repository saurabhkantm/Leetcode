class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

        int ans = 0;
        for(int i = left; i <= right; i++) {
            int set_bits = __builtin_popcount(i);
            if(primes.count(set_bits)) ans++;
        }

        return ans;
    }
};