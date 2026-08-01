class Solution {
public:
    int n;
    vector<vector<int>>dp;;
    int solve(int j,int k,vector<int>&arr,unordered_map<int,int>&mp){
        int target=arr[k]-arr[j];
        if(dp[j][k]!=-1)return dp[j][k];
        if(mp.count(target)&& mp[target]<j){
            int i=mp[target];
            return dp[j][k]=solve(i,j,arr,mp)+1;
        }
        return dp[j][k]= 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
         n=arr.size();
           dp.assign(n, vector<int>(n, -1));
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int ans=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=solve(j,k,arr,mp);
                if(len>=3){
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};
















