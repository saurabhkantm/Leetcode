class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> result = grid;
        for(int i = y; i < y + k; i++){
            int x1 = x, x2 = x + k - 1;
            while(x1 < x2){
                swap(result[x1][i], result[x2][i]);
                x1++;
                x2--;
            }
        }
        return result;
    }
};