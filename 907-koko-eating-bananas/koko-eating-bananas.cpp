class Solution {
public:
bool ispossible(int mid,vector<int>& piles,int h){
    long long hours=0;
    for(int i=0;i<piles.size();i++){
    hours+=(long long) (piles[i]+mid-1)/mid;
    }
    return hours<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end()),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(mid,piles,h)){
               ans=mid;
               high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
