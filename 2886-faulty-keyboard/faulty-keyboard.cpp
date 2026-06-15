class Solution {
public:
    string finalString(string s) {
        int n = s.length();
        for(int i =0;i<n;i++){
            if(s[i]=='i'){
                s.erase(i, 1); 
                reverse(s.begin(),s.begin()+i);
                i--;
            }
        }
        return s;
    }
};