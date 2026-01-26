class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mini_pair = INT_MAX;
        for(int i = 0; i < n-1; i++) {
            if(abs(arr[i] - arr[i+1]) < mini_pair) {
                mini_pair = abs(arr[i] - arr[i+1]);
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < n-1; i++) {
            int pair = abs(arr[i] - arr[i+1]);
            if(pair == mini_pair) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};