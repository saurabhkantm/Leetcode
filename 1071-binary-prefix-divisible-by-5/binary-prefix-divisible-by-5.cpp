class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
      vector<bool>a(n);
        int sum=0;
        for(int i=0;i<n;i++){
        sum=(sum*2+nums[i])%5;
        if(sum%5==0){
            a[i]=1;
        }
        }
    return a;
            
    } 
};