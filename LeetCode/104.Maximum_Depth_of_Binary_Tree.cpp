class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()) {
            int nodeCount = q.size();
            ++depth;
            for(int i = 0; i < nodeCount; ++i) {
                TreeNode* current = q.front();
                q.pop();
                if(current->left != nullptr) {
                    q.push(current->left);
                }
                if(current->right != nullptr) {
                    q.push(current->right);
                }
            }        
        }
        return depth;
    }
};
