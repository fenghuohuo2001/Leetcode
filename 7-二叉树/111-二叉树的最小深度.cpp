#include <algorithm>
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
    int getdepth(TreeNode* node){
        if(node==0) return 0;
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);

        if(node->right==nullptr && node->left!=nullptr){
            return 1+leftdepth;
        }
        else if(node->right != nullptr && node->left == nullptr){
            return 1+rightdepth;
        }
        return 1 + min(leftdepth, rightdepth);
    }

    int minDepth(TreeNode* root) {
        return getdepth(root);
    }
};


// µü´ú·¨
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left!=nullptr) que.push(node->left);
                if(node->right!=nullptr) que.push(node->right);
                if(node->left ==nullptr && node->right == nullptr) return depth;
            }
        }
        
        return depth;
    }
};