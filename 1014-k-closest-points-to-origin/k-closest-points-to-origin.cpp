class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        vector<vector<int>> ans;
        
        for(int i=0;i<k;i++){
            int x = points[i][0];
            int y = points[i][1];

            int ele = x*x + y*y;
            maxHeap.push({ele, i});
        }

        for(int i=k;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int ele = x*x + y*y;

            if(ele < maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({ele, i});
            }
        }

        while(!maxHeap.empty()){
            int i = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back({points[i][0], points[i][1]});
        }

        return ans;
    }
};