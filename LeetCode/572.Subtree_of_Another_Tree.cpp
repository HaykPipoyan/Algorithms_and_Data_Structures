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
    bool isSame(TreeNode* q, TreeNode* p){
        if(q == nullptr && p == nullptr){
            return true;
        }
        if(q == nullptr || p == nullptr){
            return false;
        }
        if(q->val != p->val){
            return false;
        }
        return isSame(q->left, p->left) && isSame(q->right, p->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }
        if(isSame(root, subRoot)){
               return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};
