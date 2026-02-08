class Solution {
public:
    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int leftheight = dfs(root->left);
        if(leftheight == -1) return -1;
        int rightheight = dfs(root->right);
        if(rightheight == -1) return -1;
        if(abs(leftheight - rightheight) > 1) return -1;
        return 1 + max(leftheight, rightheight);
    }
    bool isBalanced(TreeNode* root) {
       //code
        return (dfs(root) != -1);   
    }
};