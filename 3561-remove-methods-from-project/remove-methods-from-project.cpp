class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node] = true;

        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                dfs(nbr, vis, adj);
            }
        }
    };


    bool dfs1(int node, vector<bool>& vis1, vector<bool>& vis, vector<vector<int>>& adj){
        vis1[node] = true;

        for(auto nbr: adj[node]){
            if(vis[nbr]) return true;

            if(!vis1[nbr]){
                bool ans = dfs1(nbr, vis1, vis, adj);
                if(ans) return true;
            }
        }

        return false;
    }


    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }

        vector<bool>vis(n, false);
        dfs(k, vis, adj);
    
        vector<bool>vis1(n, false);
        bool found = false;
        for(int i=0; i<n; i++){
            if(!vis[i] && !vis1[i]){
                bool ans = dfs1(i, vis1, vis, adj);
                if(ans){
                    found = true;
                    break;
                }
            }
        }

        vector<int>ans;
        if(found){
            for(int i=0; i<n; i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};