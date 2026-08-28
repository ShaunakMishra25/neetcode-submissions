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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "N,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;

        return build(data, i);
    }

private:

    TreeNode* build(string& data, int& i) {

        // Read the next value
        string value;

        while (data[i] != ',') {
            value += data[i];
            i++;
        }

        i++; // skip ','

        // Null node
        if (value == "N")
            return nullptr;

        // Create current node
        TreeNode* root = new TreeNode(stoi(value));

        // Build left subtree
        root->left = build(data, i);

        // Build right subtree
        root->right = build(data, i);

        return root;
    }
};