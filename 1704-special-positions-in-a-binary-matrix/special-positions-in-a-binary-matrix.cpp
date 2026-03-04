class Solution {
public:
    bool isSpecial(int x, int y, int m, int n, vector<vector<int>>& mat){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(mat[x][i]==1) cnt++;
        }
        for(int i=0; i<m; i++){
            if(mat[i][y]==1) cnt++;
        }

        return cnt==2;
    }


    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1 && isSpecial(i, j, m, n, mat)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};