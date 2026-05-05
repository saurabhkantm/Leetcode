class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=prices[0];
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(profit>prices[i]){
               profit=prices[i];
            }
       maxi=max(maxi,prices[i]-profit);
        }
        return maxi;
    }
};