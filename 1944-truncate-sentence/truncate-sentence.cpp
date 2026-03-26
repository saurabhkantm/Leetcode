class Solution {
public:
    string truncateSentence(string s, int k) {
        string res="";
        int count=0;
        for (char ch:s){
            if (ch==' ') count++;
            if(count==k) break;
            res+=ch;
        }
        return res;
    }
};