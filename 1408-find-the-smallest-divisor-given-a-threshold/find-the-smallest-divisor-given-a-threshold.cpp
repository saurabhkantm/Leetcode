class Solution {
public:

   int division( vector<int> &nums, int threshold){
     int n = nums.size();
    int maxi = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for( int j = 0; j < n ; j++){
          
            sum += ceil(double(nums[j] )/ threshold);

            }
        return sum;
    }
   
   
    int smallestDivisor(vector<int>& nums, int threshold) {
         int low = 1;
         int high = *max_element( nums.begin(), nums.end());

         int ans = -1;

         while( low <= high){
            int mid = (low + high ) / 2;
            if(division(nums, mid) <= threshold){
                ans = mid;
                high = mid - 1;


            }
            else{
                low = mid + 1;

            }


         }
           return ans;
    }
};