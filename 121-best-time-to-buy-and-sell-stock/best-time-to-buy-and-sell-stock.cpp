class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int minbuy=prices[0];
        for(int i=1;i<n;i++){
            int profit=prices[i]-minbuy;
            maxprofit=max(maxprofit,profit);
            minbuy=min(minbuy,prices[i]);
        }
  return maxprofit;     
    }
};