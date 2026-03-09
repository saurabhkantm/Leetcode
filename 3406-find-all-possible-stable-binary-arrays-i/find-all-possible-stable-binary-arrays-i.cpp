class Solution {
public:
int mod = 1e9 + 7;

    int dp[201][201][2];
    int solve( int zero , int one , int limit ,int last_element )
    {
        if( zero == 0 && one == 0 ) return 1;

        if(dp[one][zero][last_element] != -1 ) return dp[one][zero][last_element];

        int ans = 0;

        if( last_element == 0) // now put one 
        {
            for(int x = 1 ; x <= min( one , limit ) ; x++  )
            {
                ans = (ans + solve( zero , one - x , limit , 1 )) % mod;
            }
        }
        else 
        {
            for( int x = 1 ; x <= min( zero , limit )  ; x++   )
            {
                ans = (ans + solve( zero - x , one , limit , 0 ) ) % mod ;
            }
        }


        return  dp[one][zero][last_element] = ans ;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

         memset(dp,-1,sizeof(dp));
        int ans = (solve( zero , one , limit , 0 ) + solve( zero , one , limit , 1 )) % mod;

        return ans;
    }   
};