class Solution {
public:
int ncr(int n,int r){
    int s=1;
    for(int i=0;i<r;i++){
        s*=(n-i);
        s/=i+1;
    }
    return s;
}
    vector<vector<int>> generate(int numRows) {
        //brute force
        int n=numRows;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>colRows;
            for(int j=0;j<=i;j++){
                colRows.push_back(ncr(i,j));
            }
            ans.push_back(colRows);
        }
   return ans;
    }
};