
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
    bool traversal(TreeNode* node, int count){
        // 遇到叶子节点的情况
        if(node->left == nullptr && node->right == nullptr && count == 0) return true;
        if(node->left == nullptr && node->right == nullptr) return false;

        if(node->left){
            count -= node->left->val;
            if(traversal(node->left, count)) return true;
            count += node->left->val;
        }

        if(node->right){
            count -= node->right->val;
            if(traversal(node->right, count)) return true;
            count += node->right->val;
        }
        return false;   // 不是叶子节点返回false
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return traversal(root, targetSum-root->val);
    }
};