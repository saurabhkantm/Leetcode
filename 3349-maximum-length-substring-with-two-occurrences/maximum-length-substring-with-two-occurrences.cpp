class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, int>mp;
            int currLen = 0;
            string curr = "";
            for(int j = i; j < s.size(); j++){
                if(mp[s[j]] >= 2){
                    currLen = 0;
                }
                else{
                    mp[s[j]]++;
                    currLen++;
                    maxLen = max(currLen, maxLen);
                }
            }
        }
        return maxLen;
    }
};