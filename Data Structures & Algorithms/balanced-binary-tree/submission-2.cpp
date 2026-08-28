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
    bool hBalanced = true;
    int depth(TreeNode* node){
        if(node == nullptr) return 0;

        int lDepth = depth(node->left);
        int rDepth = depth(node->right);


        if(abs(lDepth - rDepth) > 1){
            hBalanced = false;
        }
        return 1 + max(lDepth, rDepth);
    }

    bool isBalanced(TreeNode* root) {
        depth(root);
        return hBalanced;
    }
};
