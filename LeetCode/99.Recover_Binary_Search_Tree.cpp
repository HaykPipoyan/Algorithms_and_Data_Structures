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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* parent = nullptr;
        inOrder(root, first, second, parent);
        if(first && second){
            swap(first->val, second->val);
        }

    }
    void inOrder(TreeNode* current, TreeNode*& first, TreeNode*& second, TreeNode*& parent){
        if(current == nullptr){
            return;
        }
        inOrder(current->left, first, second, parent);
        if(parent && parent->val > current->val){
            if(!first) {
                first = parent;
            }
            second = current;
        }
        parent = current;
        inOrder(current->right, first, second, parent);
    }
};
