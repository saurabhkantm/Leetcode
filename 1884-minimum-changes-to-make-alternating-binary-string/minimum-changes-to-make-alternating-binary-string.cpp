class Solution {
public:
    int minOperations(string s) {
        //odd - 1
        //even - 1
        int n = s.length();
        int ans1 = 0;
        for(int i=0;i<n;i++){
            if(i%2!=0 && s[i]=='1'){
                ans1++;
            }
            else if(i%2==0 && s[i]=='0'){
                ans1++;
            }
        }
        int ans2 = 0;
        for(int i=0;i<n;i++){
            if(i%2!=0 && s[i]=='0'){
                ans2++;
            }
            else if(i%2==0 && s[i]=='1'){
                ans2++;
            }
        }
        return min(ans1,ans2);  
    }
};