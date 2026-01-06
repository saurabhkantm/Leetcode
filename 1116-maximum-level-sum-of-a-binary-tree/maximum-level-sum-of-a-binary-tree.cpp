class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1, ansLevel = 1;
        long long max_sum = root -> val;

        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            if(sum > max_sum) {
                max_sum = sum;
                ansLevel = level;
            }

            level++;
        }

        return ansLevel;
    }
};