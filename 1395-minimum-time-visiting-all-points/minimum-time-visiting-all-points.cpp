class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            int x1 = points[i-1][0], y1 = points[i-1][1];
            int x2 = points[i][0], y2 = points[i][1];
            int dx = x2 - x1;
            int dy = y2 - y1;

            // min(a, b) + abs(a - b) = max(a, b)
            ans += min(abs(dx) , abs(dy)) + abs(abs(dy) - abs(dx));
        }

        return ans;
    }
};