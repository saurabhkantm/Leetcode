class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        int n = text.length();
        for(int i=0;i<n;i++){
            mp[text[i]]++;
        }
        int ans = min({mp['b'],mp['a'],mp['l']/2,mp['o']/2,mp['n']});
        return ans;
    }
};