class Solution {
public:
    int residuePrefixes(string s) {
        vector<bool> alpha(26, false);
        int distcount=0;
        int i=0;
        int ans=0;
        for(char ch: s)
        {
            i++;
            if(alpha[ch-'a'] == false)
            {
                distcount++;
                alpha[ch-'a'] = true;
            }
            if((i%3) == distcount) ans++;
        }
        return ans;
    }
};