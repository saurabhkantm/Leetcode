class Solution {
public:
// int solve(int n,vector<int>&dp){
//     //base case
//     //if(n<=1) return n;
//     if(n==0) return 0;
//     if(n==1) return 1;
//     if(dp[n]!=-1) return dp[n];//store
//      return dp[n]=solve(n-1,dp)+solve(n-2,dp);
// }
    int fib(int n) {
        if(n<=1) return n;
    //bottom approches
    //space optimization 
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    } 
    return c;
    }
};
