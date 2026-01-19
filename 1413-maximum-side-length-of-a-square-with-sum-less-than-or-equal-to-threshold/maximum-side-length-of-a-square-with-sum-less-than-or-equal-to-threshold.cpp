class Solution {
public:
    int n, m;

    bool check(int k, vector<vector<int>> &prefix, int threshold) {
        if(k == 0) return true; // k = side length = 0 --> sum <= threshold (always)

        for(int i = k - 1; i < n; i++) { // start with a window of size k*k
            for(int j = k - 1; j < m; j++) {
                int sum = prefix[i][j];
                if(i >= k) sum -= prefix[i - k][j];
                if(j >= k) sum -= prefix[i][j - k];
                if(i >= k && j >= k) sum += prefix[i - k][j - k];

                if(sum <= threshold) return true; 
            }
        }

        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        // calculate the prefix sum matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                prefix[i][j] = mat[i][j];
                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1]; // subtracted the common part
            }
        }

        int low = 0, high = min(n, m);
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(mid, prefix, threshold)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans;
    }
};