class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for(int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int currVal = events[i][2];
            int nextStart = events[i][1] + 1; // we need to find an interval with start time >= end[i] + 1

            int low = i + 1, high = n - 1, idx = -1;
            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(events[mid][0] >= nextStart) {
                    idx = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            } 

            if(idx != -1) {
                ans = max(ans, currVal + suffixMax[idx]);
            }
            else ans = max(ans, currVal);
        }
        
        return ans;
    }
};