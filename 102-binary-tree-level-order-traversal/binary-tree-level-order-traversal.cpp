
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
              int s = q.size();
          vector<int>a;
            for(int i=0; i<s; i++){
    TreeNode*temp=q.front();
         q.pop();
        a.push_back(temp->val);
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
       q.push(temp->right);
            }
        ans.push_back(a);
        }
        return ans;
        }
};