#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 不能直接比较节点！
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 确定终止条件
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;

        // 单层递归
        // 左节点
        if(root->left==nullptr){
            return isValidBST(root->right);
        }
        if(root->right==nullptr){
            return isValidBST(root->left);
        }
        if(root->left->val < root->val && root->right->val > root->val){
            return isValidBST(root->left) && isValidBST(root->right);
        }
        else return false;
    }
};


// 使用中序遍历将二叉搜索树转为数组，判断数组是否递增即可
class Solution {
public:
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

    bool isValidBST(TreeNode* root) {
        traversal(root);
        for(int i=0; i<vec.size()-1; i++){
            if(vec[i]>=vec[i+1]) return false;
        }
        return true;
    }
};