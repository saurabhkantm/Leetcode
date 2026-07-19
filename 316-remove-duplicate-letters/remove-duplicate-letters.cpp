class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        vector<bool> inAns(26, false);
        for(char ch: s) freq[ch]++;

        string ans;
        for(char ch:s){
            if(!inAns[ch-'a']){
                while(!ans.empty() && ans.back() > ch){
                    if(freq[ans.back()] > 0){
                        inAns[ans.back()-'a'] = false;
                        ans.pop_back();
                    }
                    else break;
                }
                inAns[ch-'a'] = true;
                ans.push_back(ch);
            }
            freq[ch]--;
        }
        return ans;
    }
};