class Solution {
public:
    bool helper(const vector<int>& position, int m, int mid) {
        int count = 1; // place first ball at position[0]
        int lastPlaced = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPlaced >= mid) {
                count++;
                lastPlaced = position[i];
                if (count >= m) return true; // successfully placed all
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end()); 
        int hi =  position.back() - position.front();
        int lo = 1;

        int ans = hi - lo, mid = 0;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(helper(position,m,mid)){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        } 
        return ans;
    }
};