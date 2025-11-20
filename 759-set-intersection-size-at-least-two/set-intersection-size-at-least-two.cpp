class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1])
                return a[0] > b[0]; 
            return a[1] < b[1];     
        });
        int a = -1, b = -1;
        int count = 0;

        for (auto &in : intervals) {
            int l = in[0], r = in[1];
            bool a_in = (a >= l && a <= r);
            bool b_in = (b >= l && b <= r);
            if (a_in && b_in) {
                continue;
            }
            else if (b_in) {
                a = b;
                b = r;
                count += 1;
            }
            else {
                a = r - 1;
                b = r;
                count += 2;
            }
        }

        return count;
    }
};