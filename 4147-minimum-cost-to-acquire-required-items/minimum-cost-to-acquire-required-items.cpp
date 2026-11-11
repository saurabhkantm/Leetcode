class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       
       
       long long i=min(need1,need2);
             return i*min(costBoth,cost1+cost2)+1LL*(need1-i)*min(cost1,costBoth)+1LL*(need2-i)*min(cost2,costBoth);
            
        
    }
};