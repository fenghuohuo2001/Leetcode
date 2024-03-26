#include <queue>
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
    int traversal(TreeNode* node){
        if(node == nullptr) return 0;
        int leftsum = traversal(node->left);
        int rightsum = traversal(node->right);
        return leftsum + rightsum + 1;
    }

    int countNodes(TreeNode* root) {
        return traversal(root);
    }
};

class Solution {
public:
    int getnums(TreeNode* node){
        if(node == nullptr) return 0;
        int leftsum = getnums(node->left);
        int rightsum = getnums(node->right);
        return leftsum + rightsum + 1;
    }

    int countNodes(TreeNode* root) {
        return getnums(root);
    }
};

// 完全二叉树特性解法
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while(left){
            left = left->left;
            leftDepth++;
        }
        while(right){
            right = right->right;
            rightDepth++;
        }
        if(rightDepth == leftDepth){
            return (2<<leftDepth)-1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};