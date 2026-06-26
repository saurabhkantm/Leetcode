class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.length()-1;
        while(n>=0){
            while(n>=0 &&s[n]==' '){
               n--;
            }
            if(n<0) break;
            string word="";
            while(n>=0 && s[n]!=' '){
                word+=s[n];
                n--;
            }
            reverse(word.begin(),word.end());
            ans+=word;
            ans+=" ";

        }
        ans.pop_back();
        return ans;
    }
};