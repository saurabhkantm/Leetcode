class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int l=0,r=0,maxi=0,maxfreq=0;
        while(r<s.length()){
            freq[s[r]-'A']++;
            for(int i=0;i<26;i++){
                maxfreq=max(maxfreq,freq[i]);
            }
            while(r-l+1-maxfreq>k){
          freq[s[l]-'A']--;
          l++;
          for(int i=0;i<26;i++)
                maxfreq=max(maxfreq,freq[i]);
            }
         maxi=max(maxi,r-l+1);
         r++;
        }
        return maxi;
    }
};
