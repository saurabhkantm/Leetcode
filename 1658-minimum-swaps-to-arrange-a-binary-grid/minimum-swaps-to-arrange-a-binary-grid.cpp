class Solution {
public:
    int findRow(vector<int>&zerosInEnd,int zerosNeeded,int k){
        int n = zerosInEnd.size();
        for(int i=k;i<n;i++){
            if(zerosInEnd[i]>=zerosNeeded){
                return i;
            }
        }
        return -1;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>zerosInEnd(n);
        for(int i=0;i<n;i++){
            int zeros = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) zeros++;
                else break;
            }
            zerosInEnd[i] = zeros;
        }
        // for(int i=0;i<n;i++){
        //     cout<<zerosInEnd[i]<<endl;
        // }
        int ans = 0;
        for(int i=0;i<n;i++){
            int zerosNeeded = n - i - 1;
            int haveZeros = zerosInEnd[i];
            if(haveZeros>=zerosNeeded){
                continue;
            }
            int row = findRow(zerosInEnd,zerosNeeded,i);
            if(row==-1) return -1;
            ans += (row - i);
            while(row>i){
                swap(zerosInEnd[row],zerosInEnd[row-1]);
                row--;
            }
        }
        return ans;
    }
};