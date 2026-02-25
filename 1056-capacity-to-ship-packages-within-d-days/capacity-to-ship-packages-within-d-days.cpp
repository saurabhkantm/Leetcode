class Solution {
public:
    int daysNeeded( vector<int>& weights, int capacity){
         int days = 1;
    int currentLoad = 0;

     for( int i = 0; i< weights.size(); i++){
        if( currentLoad + weights[i] > capacity){
            days++;
            currentLoad = weights[i];
        }
        else{
            currentLoad += weights[i];
        }
     }
     return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int low = *max_element(weights.begin(), weights.end());

        int high = accumulate(weights.begin(), weights.end(), 0);

        while( low <= high){
            int mid = (low + high)/ 2;

            if(daysNeeded(weights, mid) <= days){
                ans = mid ;
                high = mid -1;
            
             }

         else{
                 low = mid +1;
              }
        
          }
    return ans ;
    }
};