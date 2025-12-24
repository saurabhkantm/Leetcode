class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int sum = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.begin(), capacity.end(), [&](const int &a, const int &b) {
            return a > b;
        });

        int take = 0;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            if(take < sum) {
                take += capacity[i];
                ans++;
            }
        }

        return ans;
    }
};