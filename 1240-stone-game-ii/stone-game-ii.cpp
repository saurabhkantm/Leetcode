class Solution {
public:
    int dp[2][101][101];
    int solve(int turn, int i, int m, vector<int>& piles){
        if(i >= piles.size())
            return 0;

        if(dp[turn][i][m] != -1)
            return dp[turn][i][m];    

        int stones = 0, res = turn == 1 ? -1 : 1e9;

        for(int x=1;x<=2*m && i+x-1 < piles.size(); x++){
            stones += piles[i+x-1];

            // Alice turn
            if(turn == 1){
                // taking max because i will do my best in my turn
                res = max(res, stones + solve(0, i+x, max(m, x), piles));
            }  
            // Bob turn
            else{
                // taking min because expecting worst from opponent
                res = min(res, solve(1, i+x, max(m, x), piles)); 
            }
        }    

        return dp[turn][i][m] = res;
    }
    int stoneGameII(vector<int>& piles) {
        //code
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, 1, piles);
    }
};