class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int l=0,r=0,maxi=0;
        while(r<s.length()){
           while(count[s[r]]){
            count[s[l]]=0;
            l++;
           }
           count[s[r]]=1;
           maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};