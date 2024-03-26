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
    TreeNode* traversal(TreeNode* t1, TreeNode* t2){
        // µÝ¹éÖÕÖ¹Ìõ¼þ
        if(t1==nullptr) return t2;
        if(t2==nullptr) return t1;

        t1->val += t2->val;

        t1->left = traversal(t1->left, t2->left);
        t1->right = traversal(t1->right, t2->right);
        return t1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return traversal(root1, root2);
    }
};