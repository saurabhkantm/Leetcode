class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
        }
        vector<int>freq2(26,0);
        int l = 0;
        int r = 0;
        int n = s2.length();
        while(r<n){
            freq2[s2[r]-'a']++;
            if(r-l+1>s1.length()){
                freq2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==s1.length()){
                bool isValid = true;
                
                for(int i=0;i<26;i++){
                    if(freq1[i]!=freq2[i]){
                        isValid = false;
                        break;
                    }
                }
                if(isValid){
                    return true;
                }
            }
            r++;
        }
        return false;
    }
};