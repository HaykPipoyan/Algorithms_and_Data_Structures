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
    void Path(TreeNode* node, string res, vector<string>& vec){
        if(node == nullptr){
            return;
        }
        if(!res.empty()){
            res += "->";
        }
        res += std::to_string(node->val);
        if(node->left == nullptr && node->right == nullptr){
            vec.push_back(res);
            return;
        }
        Path(node->left, res, vec);
        Path(node->right, res, vec);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if(root == nullptr){
            return vec;
        }
        string res;
        Path(root, res, vec);
        return vec;
    }
};
