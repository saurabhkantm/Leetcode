class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
  
        int low = 0; 
        int high = n-1;
       

        while(low<= high){
           int mid = (low + high) / 2;
           if( nums[mid] == target){
                return mid;

           }
 // if left part is sorted check with target if  exist in left or not and move low and high accordingly 
           if(nums[low] <= nums[mid]){
                if( target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                } 
                else{
                    low = mid +1;
                }    
             }

 // in this part check for element in right part neglecting the left part

           else{
                 if(target >= nums[mid] && target <= nums[high]){
                  low = mid + 1;
               }
               else{
                high = mid -1;
               }

             }
         
        }


        return  -1;
    }
};