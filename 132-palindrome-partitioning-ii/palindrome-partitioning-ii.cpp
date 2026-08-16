class Solution {
public:
bool ispalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j]){
        return false;
        }
        i++;j--;
    }
    return true;
}
int solve(int i,int j,string &s, vector<vector<int>>&dp){
    //base case
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    if(ispalindrome(i,j,s)) return 0;
    for(int k=i;k<j;k++){
        if(ispalindrome(i,k,s)){
            int cut=1+solve(k+1,j,s,dp);
            ans=min(ans,cut);
    }
    }
    return dp[i][j]=ans;
}

    int minCut(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
     return solve(0,n-1,s,dp);   
    }
};