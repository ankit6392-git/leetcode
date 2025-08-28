/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameter;

int MCA(struct TreeNode* root) {
    if (root == NULL) return 0;

    int L = MCA(root->left);
    int R = MCA(root->right);

    if (L + R > diameter) 
        diameter = L + R;   
    return 1 + (L > R ? L : R);  
}

int diameterOfBinaryTree(struct TreeNode* root) {
      diameter = 0;
    MCA(root);
    return diameter;
}
