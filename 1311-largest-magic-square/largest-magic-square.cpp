class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<long long>> row_prefix(n, vector<long long>(m, 0));
        vector<vector<long long>> col_prefix(n, vector<long long>(m, 0));
        
        // row prefix
        for(int i = 0; i < n; i++) {
            row_prefix[i][0] = grid[i][0];
            for(int j = 1; j < m; j++) row_prefix[i][j] = row_prefix[i][j-1] + grid[i][j];
        }

        // column prefix
        for(int j = 0; j < m; j++) {
            col_prefix[0][j] = grid[0][j];
            for(int i = 1; i < n; i++) col_prefix[i][j] = col_prefix[i-1][j] + grid[i][j];
        }

        for(int k = min(n, m); k >= 1; k--) {
            for(int i = 0; i <= n-k; i++) {
                for(int j = 0; j <= m-k; j++) {

                    long long target = row_prefix[i][j + k - 1]  - ((j > 0) ? row_prefix[i][j - 1] : 0);  
                    bool valid = true;

                    for(int r = i+1; r < i+k; r++) {
                        long long sum = row_prefix[r][j+k-1] - ((j > 0) ? row_prefix[r][j-1] : 0);
                        if(sum != target) {
                            valid = false;
                            break;
                        }
                    }

                    if(!valid) continue;

                    for(int c = j; c < j + k; c++) {
                        long long sum = col_prefix[i+k-1][c] - ((i > 0) ? col_prefix[i-1][c] : 0);
                        if(sum != target) {
                            valid = false;
                            break;
                        }
                    }

                    if(!valid) continue;

                    long long d1 = 0, d2 = 0; // diagonals sum
                    for(int t = 0; t < k; t++) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t]; // we wanted (j + k-1) in first iteration
                    }

                    if(d1 == target && d2 == target) return k; 
                }
            }
        }

        return 1; 
    }
};