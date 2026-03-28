class Solution {
public:
    vector<vector<int>> findLCP(string &word){
        int n = word.size();

        vector<vector<int>>lcp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            if(word[i] == word[n-1]){
                lcp[i][n-1] = 1;
                lcp[n-1][i] = 1;
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(word[i] == word[j]){
                    lcp[i][j] = 1 + lcp[i+1][j+1];
                }
            }
        }

        return lcp;
    }


    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        if(lcp[0][0] != n) return "";
        
        string word = "";
        word.push_back('a');
        for(int i=1; i<n; i++){
            vector<int>vis(26, false);
            bool found = false;
            for(int j=0; j<i; j++){
                if(lcp[j][i] == 0){
                    vis[word[j]-'a'] = true;
                }
                else{
                    found = true;
                    word.push_back(word[j]);
                    break;
                }
            }

            if(!found){
                for(int k=0; k<26; k++){
                    if(!vis[k]){
                        word.push_back('a'+k);
                        break;
                    }
                }

                if(word.size() <= i) return "";
            }
        }

        vector<vector<int>>LCP = findLCP(word);

        if(LCP == lcp) return word;
        return "";
    }
};