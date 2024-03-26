struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 反过来的中序遍历
class Solution {
private:
    int pre = 0;
    void traversal(TreeNode* cur){
        if(cur == nullptr) return;
        traversal(cur->right);      // 右
        cur->val += pre;            // 中
        pre = cur->val;
        traversal(cur->left);       // 左
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};



class Solution {
private:
    int pre = 0;
    void traversal(TreeNode* cur){
        if(cur == nullptr) return ;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};