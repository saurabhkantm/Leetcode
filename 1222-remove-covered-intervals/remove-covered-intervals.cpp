class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto&a, auto&b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();
        int cnt = n;
        for(int i = 0; i < cnt; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            for(int j = i + 1; j < cnt; j++){
                if(intervals[j][0] >= start && intervals[j][1] <= end){
                    cnt--;
                    intervals.erase(intervals.begin() + j);
                    j--;
                }
            }
        }
        return cnt;
    }
};