class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long areaSum = 0;
        int left = INT_MAX;
        int bottom = INT_MAX;
        int right = INT_MIN;
        int top = INT_MIN;

        set<pair<int,int>> points;

        for (auto &rect : rectangles) {
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];

            if (x1 >= x2 || y1 >= y2) {
                return false;
            }

            if (x1 < left) left = x1;
            if (y1 < bottom) bottom = y1;
            if (x2 > right) right = x2;
            if (y2 > top) top = y2;

            areaSum += 1LL * (x2 - x1) * (y2 - y1);

            pair<int,int> corner1 = {x1, y1};
            pair<int,int> corner2 = {x1, y2};
            pair<int,int> corner3 = {x2, y1};
            pair<int,int> corner4 = {x2, y2};

            pair<int,int> rectCorners[4] = {corner1, corner2, corner3, corner4};

            for (auto &p : rectCorners) {
                if (points.count(p)) {
                    points.erase(p);
                } else {
                    points.insert(p);
                }
            }
        }

        long long bigArea = 1LL * (right - left) * (top - bottom);

        set<pair<int,int>> bigCorners = {
            {left, bottom}, {left, top},
            {right, bottom}, {right, top}
        };

        if (areaSum != bigArea) return false;
        if (points != bigCorners) return false;

        return true;
    }
};
