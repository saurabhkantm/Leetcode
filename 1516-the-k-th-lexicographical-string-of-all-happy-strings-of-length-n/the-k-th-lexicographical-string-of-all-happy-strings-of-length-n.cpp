class Solution {
public:
    vector<string> ans;
    vector<char> letters = {'a', 'b', 'c'};

    void solve(int index, int n, string temp) {
        if(index == n+1) { // 1 based indexing
            ans.push_back(temp);
            return;
        } 

        for(int i = 0; i < 3; i++) {
            if(letters[i] != temp[index - 2]) { // coz, temp currently has length (index - 1)
                solve(index + 1, n, temp + letters[i]);
            }
        }
    }

    string getHappyString(int n, int k) {
        for(int i = 0; i < 3; i++) {
            solve(2, n, string(1, letters[i])); // can't directly pass letters[i], coz it's a char
        }

        if(k <= ans.size()) return ans[k-1];
        return "";
    }
};