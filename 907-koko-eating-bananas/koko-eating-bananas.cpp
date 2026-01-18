class Solution {
public:
    long long check(int k,vector<int>&piles){
        int n = piles.size();
        long long int hours = 0;
        for(int i=0;i<n;i++){
            hours = (long long)hours +  (long long)(piles[i] + k - 1) / k;
            
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        int l = 1;
        int r = maxi;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(mid,piles)<=h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
