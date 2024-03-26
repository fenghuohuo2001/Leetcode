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


class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return nullptr;

        // 找中节点
        int rootvalue = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootvalue);

        // 找叶子节点
        if(postorder.size() == 1) return root;

        // 找切割点
        int index = 0;
        for(; index<inorder.size(); index++){
            if(inorder[index] == rootvalue) break;
        }

        // 第四步：切割中序数组，得到 中序左数组和中序右数组 
        // 左闭右开
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        // 第五步：切割后序数组postorder，得到 后序左数组和后序右数组
        // 弹出中节点
        postorder.resize(postorder.size()-1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        // 单层递归
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};


class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        // ------------- 递归终止条件 --------------
        // 判断空节点
        if(inorder.size() == 0) return nullptr;

        // 中节点的值
        int rootvalue = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootvalue);

        // 判断叶子节点
        if(postorder.size() == 1) return root;
        
        // 分割中序
        int index = 0;
        for(; index < inorder.size(); index++){
            if(inorder[index] == rootvalue) break;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());

        // 分割后序(左右中)
        postorder.resize(postorder.size()-1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());
        
        // 单层递归
        root->left = traversal(leftInorder,leftPostorder);
        root->right = traversal(rightInorder,rightPostorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};