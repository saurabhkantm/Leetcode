class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     map<char,int>m;
     int i=0,j=0,len=0;
     while(j<s.length()){
        m[s[j]]++;
        while(m[s[j]]>1){
            m[s[i]]--;
            if(m[s[i]]==0){
                m.erase(s[i]);
        }
                i++;
        }
                len=max(len,j-i+1);
            j++;
     }
     return len;
    }
};