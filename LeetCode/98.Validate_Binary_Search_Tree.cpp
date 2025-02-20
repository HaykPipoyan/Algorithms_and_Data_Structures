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
    bool isValidBST(TreeNode* root) {
        stack<pair<TreeNode*,pair<long long, long long>>> st;
        st.push({root, {LONG_MIN, LONG_MAX}});
        while(!st.empty()){
            auto[node, range] = st.top();
            st.pop();
            long long minVal = range.first;
            long long maxVal = range.second;
            if(node->val <= minVal || node->val >= maxVal){
                return false;
            }
            if(node->right != nullptr){
                st.push({node->right, {node->val, maxVal}});
            }
            if(node->left != nullptr){
                st.push({node->left, {minVal, node->val}});
            }
        }
        return true;
    }
};
