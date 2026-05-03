class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int l=0,r=0,maxi=0;
        while(r<s.length()){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxi=max(maxi,r-l+1);
            r++;
        }
 return maxi;
    }
};
