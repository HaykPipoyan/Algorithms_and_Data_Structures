/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) {
            return 0;
        }
        std::stack<TreeNode*> st;
        TreeNode* current = root;
        int count = 0;
        TreeNode* prev = nullptr;
        while((!st.empty() || current != nullptr) && count < k){
            while(current != nullptr){
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            ++count;
            prev = current;
            current = current->right;
        }
        return prev->val;
    }
};
