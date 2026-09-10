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
    // Connects the remaining subtrees after deleting a node
    TreeNode* connector(TreeNode* root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* leftchild = root->left;
        TreeNode* leftMostChildofRightSubtree = root->right;

        // Find the leftmost node of the right subtree
        while (leftMostChildofRightSubtree->left != NULL) {
            leftMostChildofRightSubtree = leftMostChildofRightSubtree->left;
        }

        // Attach left subtree to the leftmost position of right subtree
        leftMostChildofRightSubtree->left = leftchild;

        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        // Edge case: target node is the root node
        if (root->val == key) {
            return connector(root);
        }

        TreeNode* curr = root;

        while (curr) {
            if (curr->val > key) {
                if (curr->left && curr->left->val == key) {
                    curr->left = connector(curr->left);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = connector(curr->right);
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};