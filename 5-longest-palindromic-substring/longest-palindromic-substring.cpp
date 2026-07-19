// class Solution {
// public:
//     bool isPal(string &s , int l , int r){
//         while(l < r){
//             if(s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         // cheat it untill u make it
//         int n = s.size();
//         string ans = "";

//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(isPal(s , i , j)){
//                     if(j - i + 1 > ans.size()) ans = s.substr(i , j - i + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void expand(string &s , int l , int r , int &start , int &len){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            if(r - l + 1 > len){
                len = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        // cheat it untill u make it
        int n = s.size();
        string ans = "";
        int start = 0;
        int len = 0;

        // b a b a d
        for(int i=0; i<n; i++){
            expand(s , i , i , start , len);
            expand(s , i , i + 1 , start , len);
        }
        return s.substr(start , len);

    }
};