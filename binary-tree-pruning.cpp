class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        return root;
    }
};
