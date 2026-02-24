class Solution {
public:
    int dfs(TreeNode* &root, int val){
        if(!root) return 0;

        val = (val<<1) | (root->val);
        if(!root->left && !root->right) return val;

        int left = dfs(root->left, val);
        int right = dfs(root->right, val);

        return left + right;
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};