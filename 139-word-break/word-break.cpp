class Solution {
public:
unordered_set<string>st;
bool solve(int idx, string &s, vector<int>&dp){
    if(idx==s.size()) return true;
    if(st.count(s)) return true;
    if(dp[idx]!=-1) return dp[idx];

    for(int l=1; l<=s.size(); l++){
        string str = s.substr(idx,l);
        if(st.count(str)){
            if(solve(idx+l, s,dp))  return dp[idx] =  true;
        }
    }
    return  dp[idx] = false;
}

  bool wordBreak(string s, vector<string>& wordDict) {
       int n = s.size();
       for(int i =0;i<wordDict.size(); i++){
        st.insert(wordDict[i]);
       }
       vector<int>dp(n+1,-1);
       return solve(0,s,dp);
        
    }
};