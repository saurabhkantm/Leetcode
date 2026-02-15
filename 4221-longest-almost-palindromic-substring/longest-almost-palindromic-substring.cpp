class Solution {
public:
   int solve(int i,int j,string& s,int n,vector<vector<int>>& dp){
         if(i>=j)return 0;
         if(dp[i][j]!=-1)return dp[i][j]; 
          if(s[i]==s[j]){
            return dp[i][j]= solve(i+1,j-1,s,n,dp);
          }else{
            return dp[i][j]= 1+min(solve(i,j-1,s,n,dp),solve(i+1,j,s,n,dp));
          }
   }
    int almostPalindromic(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s,n,dp)<=1){
                    maxi=max(maxi,(j-i+1));
                }
            }
        }
        return maxi;
    }
};