class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, r = 0, ans=0;
        for(char ch: s){
            if(ch=='(') l++;
            else r++;
            if(l==r) ans = max(ans, 2*r);
            else if(r>l){
                l=0; r=0;
            }
        }
        l=0;
        r=0;
        for(int i = s.size()-1; i>=0;i--){
            if(s[i] == '(') l++;
            else r++;
            if(l==r) ans = max(ans, 2*l);
            else if(l > r){
                l=0; r=0;
            }
        }
        return ans;
    }
};