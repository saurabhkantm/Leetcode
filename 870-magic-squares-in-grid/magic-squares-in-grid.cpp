class Solution {
public:
    bool isMagical(int r, int c, vector<vector<int>> &grid) {
        unordered_set<int> st; // to check uniqueness of numbers (1 to 9)

        for(int i = r; i < r+3; i++) {
            for(int j = c; j < c+3; j++) {
                int x = grid[i][j];
                if(x < 1 || x > 9 || st.count(x)) return false;
                else st.insert(x);
            }
        }

        int SUM = grid[r][c] + grid[r][c+1] + grid[r][c+2]; // calculated sum of a row 
        for(int i = 0; i < 3; i++) { 
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != SUM) return false; // all rows
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != SUM) return false; // all cols
        }

        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != SUM) return false; // diagonal
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != SUM) return false; // anti-diagonal

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n-2; i++) {
            for(int j = 0; j < m-2; j++) {
                if(grid[i+1][j+1] == 5 && isMagical(i, j, grid)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};