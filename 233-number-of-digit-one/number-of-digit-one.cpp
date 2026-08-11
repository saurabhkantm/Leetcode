class Solution {
public:
//digit dp question 
typedef long long ll;
int dp[11][2][11];
 long long solve(int i, bool tight, int count, string nums){
      if(i==nums.size()) return count;
       if(dp[i][tight][count]!=-1) return dp[i][tight][count];
       int limit=tight?nums[i]-'0':9;
       ll ans=0;
     for(int digit=0;digit<=limit;digit++){
        bool newtight=tight&&(digit==limit);
        if(digit==1){
          ans+=solve(i+1,newtight,count+1,nums);
        }
        else{
            ans+=solve(i+1,newtight,count,nums);
        }
     }
     return dp[i][tight][count]=ans;
 }
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0,true,0,to_string(n));
    }
};
