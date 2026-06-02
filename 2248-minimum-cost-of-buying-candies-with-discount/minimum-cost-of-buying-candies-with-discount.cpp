class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.rbegin(), cost.rend());
        int count=0,ans=0;
        for(int i=0;i<n;i++){
       if(count==2){
        count=0;
        continue;
       }
       ans+=cost[i];
       count++;
        }
        return ans;
    }
};