class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> store;
        int n = positions.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            store.push_back({positions[i], i});
        }
        sort(store.begin(), store.end());

        for (int i = 0; i < store.size(); i++) {
            int ind = store[i].second;
            char direction = directions[ind];

            if (direction == 'L') {
                while (!st.empty() && directions[st.top()] == 'R' && healths[st.top()] != 0) {
                    if (healths[st.top()] == healths[ind]) {
                        healths[ind] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                        break;
                    } else if (healths[st.top()] > healths[ind]) {
                        healths[st.top()]--;
                        healths[ind] = 0;
                        break;
                    } else {
                        healths[ind]--;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
                if (healths[ind] > 0) {
                    st.push(ind);
                }
            } else {
                st.push(ind);
            }
        }

        vector<int> ans;
        for (int i = 0; i < healths.size(); i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};