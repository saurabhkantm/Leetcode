class Solution {
public:
    int cont(char ch){
        if(ch=='X') return 1;
        if(ch=='Y') return -1;
        else return 0;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<pair<int, int>>> state(m, vector<pair<int, int>>(n, pair<int, int>({0, 0})));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                state[i][j].first = cont(grid[i][j]);
                state[i][j].second = (grid[i][j] == 'X');
                if(i-1>=0){
                    state[i][j].first += state[i-1][j].first;
                    state[i][j].second = state[i][j].second
                                         || state[i-1][j].second;  
                }
                if(j-1>=0){
                    state[i][j].first += state[i][j-1].first;
                    state[i][j].second = state[i][j].second 
                                        || (state[i][j-1].second);
                }
                if(i-1>=0 && j-1>=0){
                    state[i][j].first -= state[i-1][j-1].first;
                    state[i][j].second = state[i][j].second || state[i-1][j-1].second;
                }
                if(state[i][j].first==0 && state[i][j].second==1){
                    ans++;
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<state[i][j].first<<" , "<<state[i][j].second<<"    ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};