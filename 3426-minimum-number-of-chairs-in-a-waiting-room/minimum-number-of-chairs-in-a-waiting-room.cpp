class Solution {
public:
    int minimumChairs(string s) {
        int mini=0;
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='E'){
                sum++;
            }
           else{
            sum--;
           }
           mini=max(mini,sum);
        }
        return mini;
    }
};