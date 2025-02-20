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
    vector<vector<int>> levelOrder(TreeNode* root) {  
        vector<vector<int>> vec;
        if(root == nullptr){
            return vec;
        }
        int size = 0;
        queue<TreeNode*> q;
        TreeNode* current = root;
        q.push(current);
        while(!q.empty()){
            size = q.size();
            vector<int> level;
            for(int i = 0; i < size; ++i){
                current = q.front();
                q.pop();
                level.push_back(current->val);

                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }        
            }
            vec.push_back(level);
        }
        return vec;
    }
};
