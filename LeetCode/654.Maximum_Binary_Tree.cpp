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
    TreeNode* construct(vector<int>& nums, int left, int right){
        if(left >= right){
            return nullptr;
        }
        int max = INT_MIN;
        int index = -1;
        for(int i = left; i < right; ++i){
            if(max < nums[i]){
                max = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(max);

        node->left = construct(nums, left, index);
        node->right = construct(nums, index + 1, right);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) { 
        return construct(nums, 0, nums.size());
    }
};
