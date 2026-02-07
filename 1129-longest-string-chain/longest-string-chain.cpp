class Solution {
public:
    bool isPred(string curr,string prev){
        if(curr.length()!=(prev.length()+1)) return false;
        if(prev.length()==0) return true;
        int i = 0;
        int j = 0;
        while(i<curr.length() && j<prev.length()){
            if(curr[i]==prev[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==prev.length() && (i==curr.length() || i==curr.length()-1))  return true;
        return false;
    }
    // int solve(vector<string>& words,int i,int prev,vector<vector<int>>&dp){

    //     //baseCase
    //     if(i>=words.size()){
    //         return 0;
    //     }
        
    //     if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];
    //     //notTake
    //     int notTake = 0 + solve(words,i+1,prev,dp);

    //     //take
    //     int take = 0;
    //     // cout<<"curr:"<<words[i]<<endl;
    //     // cout<<"prev:"<<prev<<endl;
    //     // cout<<isPred(words[i],prev)<<endl;
    //     if(prev==-1 || isPred(words[i],words[prev])){
    //         take = 1 + solve(words,i+1,i,dp);
    //     }
    //     if(prev!=-1){
    //         return dp[i][prev] = max(take,notTake);
    //     }
    //     return max(take,notTake);
    // }
    static bool comp(string a,string b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>lis(n,1);
        int maxLen = 1;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(isPred(words[i],words[j]) && lis[j]+1>lis[i]){
                    lis[i] = lis[j]+1;
                    maxLen = max(maxLen,lis[i]);
                }
            }
        }
        return maxLen;
    }
};

