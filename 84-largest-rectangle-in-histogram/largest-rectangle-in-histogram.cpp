class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int max_area=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                //area = height*(nse-pse-1)
                max_area=max(max_area, h*(i-pse-1) );
            }
            st.push(i);
        }

        while(!st.empty()){
            int h=heights[st.top()];
            st.pop();
            int pse= st.empty() ? -1 : st.top();
            max_area=max(max_area,h*(n-pse-1));
        }
        return max_area;
    }
};