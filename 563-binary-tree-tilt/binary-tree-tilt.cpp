class Solution {
    int sum = 0;
     public :
    int dfs(TreeNode *root){
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int tilt = abs(left - right);
        sum = sum + tilt;
        return left + right + root->val;
    }
    public :
    int findTilt(TreeNode *root) {
        dfs(root);
        return sum;
    }
};