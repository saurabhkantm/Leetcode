class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>origFreq(26,0);
        for(int i=0;i<s1.length();i++){
            origFreq[s1[i]-'a']++;
        }
        int l = 0;
        int r = 0;
        int n = s2.length();
        vector<int>currFreq(26,0);
        while(r<n){
            currFreq[s2[r]-'a']++;
            if(r-l+1==s1.length()){
                bool flag = true;
                for(int i=0;i<26;i++){
                    if(origFreq[i]!=currFreq[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
                else{
                    currFreq[s2[l]-'a']--;
                    l++;
                }
            }
            r++;
        }
        return false;
    }
};