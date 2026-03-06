class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        bool check = false;
        for(int i=0; i<n; i++){
            if(s[i]=='1' && !check){
                check = true;
                while(i+1<n && s[i+1]=='1'){
                    i++;
                }
            }
            else if(s[i]=='1' && check){
                return false;
            }
        }   

        return true;
    }
};