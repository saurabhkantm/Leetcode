#define ll long long
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int md = 1e9+7;
        vector<vector<int>> dp0(zero+1,vector<int>(one+1,0));
        vector<vector<int>> dp1(zero+1,vector<int>(one+1,0));
        //base cases
        // j = 0 => all zeros
        for(int i=1; i<=min(zero,limit); i++){
            dp0[i][0] = 1; 
        }
        // i = 0 => all ones
        for(int j=1; j<=min(one,limit); j++){
            dp1[0][j] = 1; 
        }

        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                // transition for dp0[i][j]
                ll val0 = (ll)dp0[i-1][j] + dp1[i-1][j];
                if(i-limit-1>=0){
                    val0 -= dp1[i-limit-1][j];
                }
                dp0[i][j] = (val0%md + md)%md;

                // transition for dp1[i][j]

                ll val1 = (ll)dp0[i][j-1] + dp1[i][j-1];
                if(j-limit-1>=0){
                    val1 -= dp0[i][j-limit-1];
                }
                dp1[i][j] = (val1%md + md)%md;
            }
        }

        return ((ll)dp0[zero][one] + dp1[zero][one])%md;
    }
};