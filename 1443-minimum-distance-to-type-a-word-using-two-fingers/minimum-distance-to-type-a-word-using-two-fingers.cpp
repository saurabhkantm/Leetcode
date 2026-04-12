class Solution {
public:
    // bool isPresent(char ch,string s){
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]==ch){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    int calcDist(char ch1,char ch2){
        int past = ch1-'A';
        int present = ch2-'A';
        int xPast = past/6;
        int yPast = past%6;
        int xPresent = present/6;
        int yPresent = present%6;
        return abs(xPresent - xPast) + abs(yPresent - yPast);
    }
    int solve(string word,int f1,int f2,int i,vector<vector<vector<int>>>&dp){
        if(i==word.length()){
            return 0;
        }

        if(dp[f1][f2][i]!=-1){
            return dp[f1][f2][i];
        }

        int t1 = INT_MAX/2;
        int t2 = INT_MAX/2;
        
        if(f1==26){
            t1 = solve(word,word[i]-'A',f2,i+1,dp);
        }
        if(f1!=26){
            t1 = calcDist(f1+'A',word[i]) + solve(word,word[i]-'A',f2,i+1,dp);
        }
        if(f2==26){
            t2 = solve(word,f1,word[i]-'A',i+1,dp);
        }
        if(f2!=26){
            t2 = calcDist(f2+'A',word[i]) + solve(word,f1,word[i]-'A',i+1,dp);
        }
        return dp[f1][f2][i] = min(t1,t2);
    }
    int minimumDistance(string word) {
        int n = word.length();
        vector<vector<vector<int>>>dp(27,vector<vector<int>>(27,vector<int>(301,-1)));
        int ans = solve(word,26,26,0,dp);
        return ans;
    }
};