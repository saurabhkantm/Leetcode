class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long count=0,previous;
        long long length=0;
        for(int i=0;i<n;i++){
            if(i>0&&prices[i]==previous-1){
               length++;
            }
            else{
                length=1;
            }
           count+=length;
            previous=prices[i];
        }
        return count;
    }

};