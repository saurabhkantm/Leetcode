class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long sum=0;
        for(int i=0;i<happiness.size() && i<k;i++){
            int actualhappiness=max(happiness[i]-i,0);
            sum+=actualhappiness;
        }
        return sum;
    }
};