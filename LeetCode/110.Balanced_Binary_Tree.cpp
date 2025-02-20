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
    int getHeight(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    int getBalance(TreeNode* node){
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        if(getBalance(root) > 1 || getBalance(root) < -1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
