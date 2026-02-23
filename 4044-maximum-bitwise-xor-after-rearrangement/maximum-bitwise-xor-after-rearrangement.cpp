class Solution {
public:
    string maximumXor(string s, string t) {
        int zero=0, one=0;
        for(auto i:t){
            if(i=='0') zero++;
            else one++;
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(one>0){
                    ans+='1';
                    one--;
                }
                else {
                    ans+='0';
                    zero--;
                }
            }
            else {
                if(zero>0){
                    ans+='1';
                    zero--;
                }
                else {
                    ans+='0';
                    one--;
                }
            }
        }
        
        return ans;
    }
};