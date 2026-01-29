class Solution {
public:
    void FloydWarshall(vector<vector<long long>> &dist, vector<char> &original, vector<char> &changed, vector<int> &cost) {

        for(int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // apply floyd warshall
        for(int via = 0; via < 26; via++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }  

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));

        FloydWarshall(dist, original, changed, cost);

        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(source[i] == target[i]) continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(dist[u][v] == INT_MAX) return -1;
            ans += dist[u][v];
        }

        return ans;
    }
};