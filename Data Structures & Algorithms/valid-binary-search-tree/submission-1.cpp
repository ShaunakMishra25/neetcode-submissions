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
   private:
    bool helper(TreeNode* root, int lb, int ub) {
        if (root == nullptr) return true;
        if (!(root->val > lb && root->val < ub)) {
            return false;
        }

        bool leftValid = true, rightValid = true;
        if(root->left){
            leftValid = helper(root->left, lb, root->val);
        }
        if(root->right){
            rightValid = helper(root->right, root->val, ub);
        }

        return leftValid && rightValid;
    }

   public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
