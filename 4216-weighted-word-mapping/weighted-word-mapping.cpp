class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string r="";
        for(string word:words){
        int t=0;
        for(char ch:word){
            t+=weights[ch-'a'];
        }
        int rem=t%26;
        char mc='z'-rem;
        r+=mc;
    }
        return r;
    }
};