class Solution {
public:
    int xorOperation(int n, int start) {
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt^=start+2*i;
        }
        return cnt;
    }
};