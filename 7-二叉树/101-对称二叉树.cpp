#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _x): val(_x), left(nullptr), right(nullptr){}
};

// 后序遍历-递归-左右中
void post_traversal(TreeNode* cur, vector<int> &_result){
    if(cur == nullptr) return;
    post_traversal(cur->left, _result);
    post_traversal(cur->right, _result);
    _result.push_back(cur->val);
}

// 后序遍历-迭代-左右中
void post_traversal_iter(TreeNode* root, vector<int> &result){
    stack<TreeNode*> st;
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        if(node != nullptr){
            st.pop();
            st.push(node);
            st.push(nullptr);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }else{
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
}


/* 均可以分解为子树的外侧和内侧是否相等 */
// 递归法
class Solution {
public:
    // 确定递归参数和返回值
    bool compare(TreeNode* left, TreeNode* right){
        // 确定终止条件
        if(left==nullptr && right!=nullptr) return false;
        else if(left!=nullptr && right==nullptr) return false;
        else if(left==nullptr && right==nullptr) return true;
        else if(left->val != right->val) return false;
        // 比较外侧是否对称
        bool outside = compare(left->left, right->right);
        // 比较内侧是否对称    
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

class Solution{
public:
    bool compare(TreeNode* left, TreeNode* right){
        if(left!=nullptr && right==nullptr) return false; 
        else if(left==nullptr && right!=nullptr) return false; 
        else if(left==nullptr && right==nullptr) return true;
        else if(left->val != right->val) return false;

        bool outside = compare(left->left, right->right); 
        bool inside = compare(left->right, right->left);
        return outside && inside; 
    }

    bool isSymmetric(TreeNode* root){
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
};


// 迭代法
class Solution{
public:
    bool isSymmetric(TreeNode* root){
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        
        while(!que.empty()){
            TreeNode* leftnode = que.front();
            que.pop();
            TreeNode* rightnode = que.front();
            que.pop();
            // 先判断是否为空
            if(leftnode==nullptr && rightnode==nullptr){
                continue;
            }
            
            if(leftnode==nullptr || rightnode==nullptr || (leftnode->val != rightnode->val)){
                return false;
            }
            // 当均不为空且相等时
            que.push(leftnode->left);
            que.push(rightnode->right);
            que.push(leftnode->right);
            que.push(rightnode->left);
        }
        return true;
    }
};


class Solution{
public:
    bool compare(TreeNode* left, TreeNode* right){
        if(left==nullptr && right!=nullptr) return false;
        else if(left!=nullptr && right==nullptr) return false;
        else if(left==nullptr && right==nullptr) return true;
        else if(left->val != right->val) return false;
        return compare(left->left, right->right) && compare(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root){
        // 先判断root
        if(root == nullptr) return true;
        // 再写递归
        return compare(root->left, root->right);
    }
};

class Solution{
public:
    bool isSymmetric(TreeNode* root){
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode* leftnode = que.front();
            que.pop();
            TreeNode* rightnode = que.front();
            que.pop();
            if(leftnode==nullptr && rightnode==nullptr){
                continue;
            }

            if(leftnode==nullptr || rightnode==nullptr || (leftnode->val != rightnode->val)){
                return false;
            }

            que.push(leftnode->left);
            que.push(rightnode->right);
            que.push(leftnode->right);
            que.push(rightnode->left);


        }
        return true;
    }
};