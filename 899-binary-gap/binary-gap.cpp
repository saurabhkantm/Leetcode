class Solution {
public:
    int binaryGap(int n) {
        string s = "";
        while(n){
            int d = n&1;
            s += (d+'0');
            n >>= 1;
        }    

        int i=0;
        int size = s.size();
        while(i<size && s[i] == '0'){
            i++;
        }

        if(i >= size) return 0;

        int cnt = 0;
        int ans = 0;
        while(i<size){
            if(s[i] == '0')
                cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }

            i++;
        }

        return ans;
    }
};