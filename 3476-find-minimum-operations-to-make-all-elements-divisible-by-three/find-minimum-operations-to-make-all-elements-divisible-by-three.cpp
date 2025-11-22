class Solution {
public:
    int minimumOperations(vector<int>& nums) {
    
        int count =0;
        for(auto num:nums){
            if(num%3!=0)
            count++;
        }
        return count;
    }
};