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
    // 递归
    void traversal(TreeNode* cur, vector<int> &path, vector<string> &result){
        path.push_back(cur->val);
        // 当遍历到叶子节点时就终止
        if(cur->left == nullptr && cur->right == nullptr){
            string spath;
            for(int i=0; i<path.size()-1; i++){
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size()-1]);
            result.push_back(spath);
            return;
        }
        if(cur->left){
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if(cur->right){
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root==nullptr) return result;
        traversal(root, path, result);
        return result;
    }
};


class Solution {
public:
    // 递归 前序遍历，中左右
    void traversal(TreeNode* cur, vector<int> &path, vector<string> &result){
        // 中
        path.push_back(cur->val);
        // 递归终止条件
        if(cur->left == nullptr && cur->right==nullptr){
            // 将当前path转换为string
            string spath;
            for(int i=0; i<path.size()-1; i++){
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size()-1]);
            result.push_back(spath);
        }

        if(cur->left){
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if(cur->right){
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root == nullptr) return result;
        traversal(root, path, result);
        return result;
    }
};