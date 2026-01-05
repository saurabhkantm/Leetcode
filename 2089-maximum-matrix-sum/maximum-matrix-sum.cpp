class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // if even number of negative elememts --> all can be converted to positive
        // if odd number of -ve elements --> only 1 will remain. (we will keep that one ele to be the element with min absolute value)

        int count = 0;
        long long tot_sum = 0, min_el = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] < 0) count++;
                tot_sum += abs(matrix[i][j]);
                if(abs(matrix[i][j]) < min_el) min_el = abs(matrix[i][j]);
            }
        }

        if(count % 2 == 0) return tot_sum;
        return tot_sum - 2*min_el;
    }
};