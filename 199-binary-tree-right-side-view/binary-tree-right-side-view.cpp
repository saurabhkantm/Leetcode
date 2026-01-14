void total(TreeNode* root,  vector<int>&ans,int level){
    if(root==nullptr) return ;
    if(ans.size()==level){
        ans.push_back(root->val);
    }
        // if(root->right)
        total(root->right,ans,level+1);
        total(root->left,ans,level+1);
       }
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
       total(root,ans,0);
       return ans; 
    }
};