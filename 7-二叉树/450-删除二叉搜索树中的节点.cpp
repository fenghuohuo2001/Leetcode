struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* ---
考虑五种删除情况
1. 没找到删除节点
2. 删除叶子节点
3. 删除节点左不空 右空
4. 删除节点左空 右不空
5. 删除节点左不空 右不空



*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;        // 第一种情况 未找到删除节点，遍历到空节点直接返回

        if(root->val == key){
            // 叶子节点
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } 
            else if(root->left != nullptr && root->right == nullptr) {
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }
            else if(root->left == nullptr && root->right != nullptr) {
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
            else{
                TreeNode* cur = root->right;
                while(cur->left) cur = cur->left;
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};