class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>&curr,vector<bool>&visited,vector<int>&nums){
    if(curr.size()==nums.size()){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i])
        continue;
        visited[i]=1;
        curr.push_back(nums[i]);
        solve(ans,curr,visited,nums);
        visited[i]=0;
        curr.pop_back();
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool>visited(nums.size(),0);
        solve(ans,curr,visited,nums);
        return ans;
    }
};