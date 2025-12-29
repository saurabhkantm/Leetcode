class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo; // full-state memo

    bool dfs(string &bottom, int idx, string nextRow) {
        // If this state was already solved, reuse result 
        string key = bottom + "_" + to_string(idx) + "_" + nextRow;
        if (memo.count(key)) return memo[key];

        if(idx == bottom.size() - 1) {
            if(nextRow.size() == 1) return memo[key] = true;
            return memo[key] = dfs(nextRow, 0, "");
        }

        string check = bottom.substr(idx, 2);
        if(!mp.count(check)) return memo[key] = false;

        for(auto &ch: mp[check]) {
            if(dfs(bottom, idx+1, nextRow + ch)) return memo[key] = true;
        }

        return memo[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }

        return dfs(bottom, 0, "");
    }
};