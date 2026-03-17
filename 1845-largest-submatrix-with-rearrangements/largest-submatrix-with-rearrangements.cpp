class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(matrix[i][j] == 0) 
                    continue;
                matrix[i][j] += matrix[i-1][j]; 
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            sort(matrix[i].rbegin(), matrix[i].rend());
            int mini = INT_MAX;
            
            for(int j=0;j<m;j++){
                mini = min(mini, matrix[i][j]);
                ans = max(ans, mini*(j+1));
            }
        }

        return ans;
    }
};