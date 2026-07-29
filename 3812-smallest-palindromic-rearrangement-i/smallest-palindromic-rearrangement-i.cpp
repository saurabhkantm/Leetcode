class Solution {
public:
    bool isPal(string &s){
        int i=0 , j = s.size() - 1;
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    string smallestPalindrome(string s) {
        // sort(s.begin() , s.end());
        // string ans= "";

        // do{
        //     if(isPal(s)){
        //         ans = s;
        //         break;
        //     }
        // } while(next_permutation(s.begin() , s.end()));

        // return ans;
        vector<int> freq(128 , 0);
        for(char ch : s) freq[ch]++;

        string left= "";
        char mid = '\0';

        for(int ch='a'; ch<='z'; ch++){
            while(freq[ch] >= 2){
                left += ch;
                freq[ch] -= 2;
            }
            if(freq[ch] == 1) mid = ch;
        }
        string right = left;
        reverse(right.begin() , right.end());

        if(mid != '\0') return left + mid + right;

        return left + right;















    }
};