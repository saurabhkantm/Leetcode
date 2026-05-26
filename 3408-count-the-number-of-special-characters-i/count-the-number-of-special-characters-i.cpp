class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> freq1(26, 0), freq2(26, 0);
        int res = 0;
        for(char ch : word){
            if(ch >= 'a' && ch <= 'z'){
                freq1[ch - 'a']++;
            }else{
                freq2[ch - 'A']++;
            }
        }
        for(int i = 0; i < 26; i++){
            if(freq1[i] && freq2[i])res++;
        }
        return res;
    }
};