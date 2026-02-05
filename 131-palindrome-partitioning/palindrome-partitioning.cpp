class Solution {
public:
 bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
void palindrome(int idx, vector<vector<string>>&ans, vector<string>&curr,string &s){
    if(idx==s.size()){
        ans.push_back(curr);
        return;
    }
    for(int i = idx; i < s.size(); i++) {
        if(isPalindrome(s,idx,i)){
        curr.push_back(s.substr(idx, i - idx + 1));// idar kuch condtion bane gi but kya bane gi socho socho?
        palindrome(i + 1, ans, curr,s);
        curr.pop_back(); // backtrack
     }
    }
}
    vector<vector<string>> partition(string s) {
       vector<vector<string>>ans;
       vector<string>curr;
       palindrome(0,ans,curr,s);
       return ans;
    }
};