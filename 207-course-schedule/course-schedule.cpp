class Solution {
public:
    // topological sort (kanh's algorithm)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        for(auto &e:prerequisites){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i] == 0)
                q.push(i);
        }


        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(int neighb:adj[node]){
                inDeg[neighb]--;
                if(inDeg[neighb] == 0)
                    q.push(neighb);
            }
        }

        return cnt == numCourses;
    }
};