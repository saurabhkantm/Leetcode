class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        vector<int>ans;
        while(i<j){
        if(numbers[i]+numbers[j]==target){
          return  {i+1,j+1};
        }
        else if(numbers[i]+numbers[j]<target){
            i++;
        }
        else{
            j--;
        }
        }
        return ans;                  //numbers = [2,7,11,15], target = 9
                                    //i=0 j=3 2+15=17
    }                              // i=0,j=2   2+11=13
                                   // i=0 j=1   2+7=9
};
         