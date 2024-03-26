#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _x): val(_x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int getdepth(TreeNode* node){
        if(node == nullptr) return 0;
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);
        int depth = 1+max(leftdepth, rightdepth);
        return depth;
    }

    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};


class Solution {
public:
    int getdepth(TreeNode* node){
        if(node == nullptr) return 0;
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);
        int depth = 1 + max(leftdepth, rightdepth);
        return depth;
    }

    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};


#include <queue>
// 迭代法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;

        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->right) que.push(node->right);  // 这里的顺序没有影响
                if(node->left) que.push(node->left);
            }
        }

        return depth; 
    }
};
