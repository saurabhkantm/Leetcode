class Solution {
public:
    int calc(vector<int> &heights, int n) {
        stack<int> st;
        int maxArea = 0;
        int nse, pse, width;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = heights[st.top()];
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                width = nse - pse - 1;
                maxArea = max(maxArea, element * width);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int element = heights[st.top()];
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            width = nse - pse - 1;
            maxArea = max(maxArea, element * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;
        vector<int> height(m, 0);

        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            int area = calc(height, m);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};