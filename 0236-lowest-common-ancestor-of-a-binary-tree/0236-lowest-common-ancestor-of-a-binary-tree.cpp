/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // If tree is empty, return NULL
        if (root == NULL) {
            return NULL;
        }

        // If current node is p or q,
        // current node can be the LCA
        if (root == p || root == q) {
            return root;
        }

        // Search for p and q in the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search for p and q in the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found on different sides,
        // current root is their LCA
        if (left != NULL && right != NULL) {
            return root;
        }

        // If only left side has a node, return left
        // Otherwise return right
        return left != NULL ? left : right;
    }
};