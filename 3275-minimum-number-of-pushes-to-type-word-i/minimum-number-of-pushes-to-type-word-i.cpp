class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<8)return n;
        int i=0;
        int ans=0;
        int round=1;
        while(i<n){
            if(i%8==0 && i!=0){
                round++;
            }
            ans+=round;
            i++;
        }
        return ans;
    }
};