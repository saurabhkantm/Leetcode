class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int depth(TreeNode* root) {
        if(root == NULL) return 0;
        if(dp.count(root)) return dp[root];

        return dp[root] = max(depth(root -> left), depth(root -> right)) + 1;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d = depth(root -> left) - depth(root -> right);
        if(d == 0) return root;
        else if(d > 0) return subtreeWithAllDeepest(root -> left);
        return subtreeWithAllDeepest(root -> right);
    }
};