class Solution {
public:
    int lengthOfLastWord(string s) {
        int z  =s.size()-1;
        int len = 0;
        while(z >= 0 && s[z] == ' '){
            z--;
        }
         while(z >= 0 && s[z] != ' '){
            len++;
            z--;
        }
        return len;
    }
};