class Solution {
public:
    const int MOD=1e9+7;
    int waysToTarget(int i,int points,int target, vector<vector<int>>& types,vector<vector<int>> &dp){
         if(i>=types.size()){
            return points==target;
         }
         if(points==target)return 1;
         if(points>target)return 0;
          if(dp[i][points]!=-1){
            // cout<<"A"<<endl;
            return dp[i][points];
          }
         int ways=0;
           int not_take=waysToTarget(i+1,points,target,types,dp);
          for(int k=1;k<=types[i][0]; k++){
             ways=(ways+waysToTarget(i+1,points+(k*types[i][1]),target,types,dp))%MOD;
          }
          return dp[i][points]=(ways+not_take)%MOD;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
         vector<vector<int>> dp(n+1,vector<int>(target+2,-1));
          return waysToTarget(0,0,target,types,dp);
    }
};