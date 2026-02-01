class Solution {
public:
    int canSplit(int sum,vector<int>&nums){
        int splits = 1;
        int currSum = 0;
        // cout<<"sum"<<sum<<endl;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(currSum>sum){
                splits++;
                currSum = nums[i];
            }
        }
        // cout<<splits<<endl;
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            cout<<canSplit(mid,nums)<<endl;
            if(canSplit(mid,nums)<=k){
                // cout<<"Here"<<endl;
                ans = mid;
                r = mid - 1;
            }
            else{
                // cout<<"Else"<<endl;
                l = mid + 1;
            }
        }
        return ans;
    }
};