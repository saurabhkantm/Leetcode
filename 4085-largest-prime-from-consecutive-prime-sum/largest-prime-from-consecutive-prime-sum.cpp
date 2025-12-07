class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n + 1, true);
    // mark non-primes (Sieve)
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int sum = 0;
    int res = 0;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            sum += i;

            if (sum > n) break;

            if (isPrime[sum]) {
                res = sum;
            }
        }
    }
    return res;
}
};