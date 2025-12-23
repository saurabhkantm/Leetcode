class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &list, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : list[node]) {
            if(it == parent) continue;
            if(vis[it] == 0) {
                dfs(it, node, vis, list, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // whether node -- it is possible or not
                if(low[it] > tin[node]) { // not possible
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> list(n);
        for(auto it : connections) {
            int u = it[0];
            int v = it[1];

            list[u].push_back(v);
            list[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> bridges;
        dfs(0, -1, vis, list, tin, low, bridges);
        return bridges;
    }
};