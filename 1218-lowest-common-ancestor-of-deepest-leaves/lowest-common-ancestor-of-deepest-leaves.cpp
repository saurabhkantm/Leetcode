class Solution {
public:
    int depth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left == right)
            return root;
        else if(left > right)
            return lcaDeepestLeaves(root->left);
        else
            return lcaDeepestLeaves(root->right);
    }
};
