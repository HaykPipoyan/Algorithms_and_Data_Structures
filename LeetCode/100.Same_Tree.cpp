class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) {
            return true;
        } 
        if(p == nullptr || q == nullptr) {
            return false;
        }
        std::stack<TreeNode*> stp;
        stp.push(p);
        std::stack<TreeNode*> stq;
        stq.push(q);

        while(!stp.empty() && !stq.empty()) {
            TreeNode* nodeQ = stq.top();
            TreeNode* nodeP = stp.top();
            stq.pop();
            stp.pop();
            
            if(nodeP == nullptr && nodeQ == nullptr) {
                continue;
            }
            if(nodeP == nullptr || nodeQ == nullptr || nodeP->val != nodeQ->val) {
                return false;
            }
            stq.push(nodeQ->right);
            stq.push(nodeQ->left);
            stp.push(nodeP->right);
            stp.push(nodeP->left);
        }
        return stp.empty() && stq.empty();
    }
};
