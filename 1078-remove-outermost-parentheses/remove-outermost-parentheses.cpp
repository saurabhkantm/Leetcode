class Solution {
public:
    string removeOuterParentheses(string s) {
        string r;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(count>0){
                    r+=s[i];
                }
                count++;
            }
            else{
                count--;
                if(count>0){
                    r+=s[i];
                }
            }
        }
        return r;
    }
};