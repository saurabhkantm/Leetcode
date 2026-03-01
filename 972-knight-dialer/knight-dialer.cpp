class Solution {
public:
    const int MOD=1000000007;
    int dialer(int n,int num,vector<vector<int>> &numbers,vector<vector<int>> &dp){
        if(n==0)return 1;
        if(dp[n][num]!=-1){
            return dp[n][num];
        }
        int count=0;
        for(int i=0; i<numbers[num].size();i++){
            count=(count+dialer(n-1,numbers[num][i],numbers,dp))%MOD;
        }
        return dp[n][num]=count%MOD;
    }
    int knightDialer(int n) {
         vector<vector<int>> numbers{{6,4},{6,8},{7,9},{4,8},{9,3,0},{},{1,7,0},{6,2},{1,3},{2,4}};
         vector<vector<int>> dp(n+1,vector<int>(10,-1));
         int ans=0;
         if(n==1)return 10;
         for(int num=0;num<=9;num++){
             if(num==5){
                continue;
             }
             ans=(ans+dialer(n-1,num,numbers,dp))%MOD;
         }
         return ans;
    }
};