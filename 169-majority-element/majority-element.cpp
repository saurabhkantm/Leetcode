class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        int freq=INT_MIN;
        int val=0;
        for(auto it:mp){
            if(freq<it.second){
                freq= it.second;
                val= it.first;
            }
        }
        return val;
    }
};