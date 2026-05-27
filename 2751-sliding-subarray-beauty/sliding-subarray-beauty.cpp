class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
     int n=nums.size();
     vector<int>ans;
     map<int,int>m;
     int i=0,j=0,count=0;
     while(j<n){
        if(nums[j]<0){
       m[nums[j]]++;
       count++;
        }
        if(j-i+1==k){
            //ans cal
            if(count<x) ans.push_back(0);
            else{
              int  count=x;
              for(auto it:m){
              if(it.second>=count){
             ans.push_back(it.first);
             break;
              }
              else{
                count-=it.second;
              }
              }
            } 
            if(nums[i]<0){
                m[nums[i]]--;
                count--;
            }
            i++;
        }
        j++;
     } 
     return ans;
    }
};