class Solution {
public:
int diameter=0;
int check(TreeNode*root){
    if(!root) return 0;
    int left=check(root->left);
    int right=check(root->right);
    diameter=max(diameter,left+right);
    return 1+max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return diameter;
    }
};