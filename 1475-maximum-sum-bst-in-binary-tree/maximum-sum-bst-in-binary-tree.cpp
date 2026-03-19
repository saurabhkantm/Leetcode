
class Solution {
public:
    struct Node{
        int minVal;
        int maxVal;
        bool isBST;
        int sum;
    };

    int ans;
    Node solve(TreeNode* &root){
        if(!root) return {INT_MAX, INT_MIN, true, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.isBST && right.isBST && 
            root->val > left.maxVal && root->val < right.minVal){
            int mini = min(root->val, left.minVal);
            int maxi = max(root->val, right.maxVal);
            int curr = left.sum + right.sum + root->val;
            ans = max(ans, curr);
            return {mini, maxi, true, curr};
        } 

        return {INT_MIN, INT_MAX, false, 0};
    }


    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};