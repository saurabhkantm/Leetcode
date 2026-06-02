class Solution {
public:
    void solve(TreeNode* root, vector<string>& ans, string temp)
    {
        temp += to_string(root->val);

        if(root->left == nullptr && root->right==nullptr)
        {
            ans.push_back(temp);
            return;
        }
        temp += "->";
        if(root->left) solve(root->left, ans, temp );
        if(root->right) solve(root->right, ans, temp );
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        string temp ="";
        solve(root, ans, temp);
        return ans;
    }
};