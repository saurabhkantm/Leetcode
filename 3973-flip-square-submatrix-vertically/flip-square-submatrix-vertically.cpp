class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int n1 = x+k;
        int n2 = y+k;

        for(int i=x; i<n1 && k>=1 ; i++){
            for(int j=y; j<n2 && k>=1; j++){
                // cout << i << "-> " << i+k-1 << endl;
                swap(grid[i][j], grid[i+k-1][j]);
            }
            k -= 2;
        }

        return grid;        
    }
};