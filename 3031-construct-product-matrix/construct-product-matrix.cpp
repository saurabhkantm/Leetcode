class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        vector<int>arr;

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>ans(row,vector<int>(col));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
        }

        int n = arr.size();

        vector<long long>prefix(n);
        vector<long long>suffix(n);

        const int mod = 12345;

        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];

        for(int i=1;i<n;i++){
            prefix[i] = (prefix[i-1] * arr[i]) % mod;
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] = (suffix[i+1] * arr[i]) % mod;
        }
        // for(int i=0;i<n;i++){
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<suffix[i]<<" ";
        // }
        for(int i=0;i<n;i++){
            long long left = 1;
            long long right = 1;
            if(i-1>=0){
                left = prefix[i-1];
            }
            if(i+1<n){
                right = suffix[i+1];
            }
            // cout<<left<<" "<<right;
            // cout<<endl;
            long long take = (left * right) % mod;
            // cout<<take<<endl;
            ans[i/col][i%col] = take;
        }
        return ans;
    }
};