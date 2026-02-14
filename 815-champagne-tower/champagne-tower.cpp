class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        //code
        vector<vector<double>> arr(102, vector<double>(102, 0));
        arr[0][0] = poured;
        for(int i=0;i<query_row;i++){
            bool flag = false;
            for(int j=0;j<=i;j++){
                if(arr[i][j] > 1.0){
                    double rem = arr[i][j] - 1.0;
                    arr[i][j] = 1;
                    arr[i+1][j] += rem/2.0;
                    arr[i+1][j+1] += rem/2.0;

                    flag = true;
                }
            }
            if(!flag) break;
        }
        double ans = arr[query_row][query_glass];
        return ans > 1.0 ? 1.0 : ans;
    }
};