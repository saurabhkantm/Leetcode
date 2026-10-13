class Solution {
public:
    bool isAllStars(string& s, int i)
    {
        for(int j=1; j<=i; j++)
        {
            if(s[j-1] != '*') return false;
        }
        return true;
    }

    bool isMatch(string s, string p) 
    {
        int n= s.length();
        int m= p.length();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true; //empty patter, empty text

        for(int i=1; i<=m; i++) //first col
        {
            dp[0][i] = isAllStars(p, i); //empty text
        }

        for(int j=1; j<=n; j++)
        {
            dp[j][0] = false; //empty pattern
        }

        //fil the dp table
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                //chars match or we get '?'
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[n][m];
        
    }
};