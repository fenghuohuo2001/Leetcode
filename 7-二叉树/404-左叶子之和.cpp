#include <vector>
#include <string>
using namespace std;

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
    int sumOfLeftLeaves(TreeNode* root) {
        // 递归 后序遍历
        if(root == nullptr) return 0;       // 空节点的左叶子节点为0
        // 遇到叶子节点，其左叶子节点也为0
        if(root->left==nullptr && root->right==nullptr) return 0;
        // 按照左右中的顺序遍历
        int leftValue = sumOfLeftLeaves(root->left);    // 左
        // 判断左叶子节点
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            leftValue = root->left->val;
        }   // 中
        int rightValue = sumOfLeftLeaves(root->right);      // 右
        return leftValue + rightValue;
    }
};