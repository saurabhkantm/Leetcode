class Solution {
public:
    int dp[101][101];
    int solve( string &s , int l , int r)
    {
        if(l > r) return 0;
        if(l == r) return 1;

            if(dp[l][r] != -1)  return dp[l][r];

        int ans = 1 + solve( s , l+1 , r ); // check the lenght for same character

        for(int x = l+1 ; x <= r ; x++ )
        {
            if(s[x] == s[l])
            {
            int temp = solve(s,l+1 , x-1) + solve(s , x , r);

            ans = min(ans, temp);}
        }


        return dp[l][r] = ans;
    }
    int strangePrinter(string s) {
        int n = s.size();

        memset(dp,-1,sizeof(dp));       

        return solve(s,0,n-1);
    }
};