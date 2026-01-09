class Solution {
public:
    vector<string>ans;
    void rec(int open, int close, int n, string curr){

        if(open == close && open + close == 2 * n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            rec(open + 1, close, n, curr + '(');
        }
        if(open > close && close < n){
            rec(open, close + 1, n, curr + ')');
        }
    }

    vector<string> generateParenthesis(int n) {

        
        rec(0,0, n, "");
        return ans;
        
    }
};