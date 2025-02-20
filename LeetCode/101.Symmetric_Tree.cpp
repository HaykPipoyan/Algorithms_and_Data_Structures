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
    bool isSame(TreeNode* Left, TreeNode* Right){
        if(!Left && !Right){
            return true;
        }
        if(!Left || !Right){
            return false;
        }
        if(Left->val != Right->val){
            return false;
        } 
        return isSame(Left->left, Right->right) && isSame(Left->right, Right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};
