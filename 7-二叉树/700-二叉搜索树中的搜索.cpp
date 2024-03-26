struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // ÖÕÖ¹Ìõ¼þ
        if(root == nullptr || root->val == val) return root;

        TreeNode* result = nullptr;
        if(root->val > val) result = searchBST(root->left, val);
        if(root->val < val) result = searchBST(root->right, val);
        
        return result;
    }
};