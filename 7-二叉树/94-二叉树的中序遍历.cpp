#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _x): val(_x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    // 中序遍历是 左中右
    void traversal(TreeNode *cur, vector<int> &_result){
        if(cur == nullptr) return;
        traversal(cur->left, _result);
        _result.push_back(cur->val);
        traversal(cur->right, _result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

#include <stack>
// 迭代法
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        // 中序遍历是左中右
        while(cur != nullptr || !st.empty()){
            if(cur!=nullptr){
                st.push(cur);
                cur = cur->left;        // 遍历到最左结点， 若下一个是nullptr则不会入栈
            }else{
                cur = st.top();         // 取出左结点
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;       // 第一次的right结点也为空，因此取中结点
            }
        }
        return result;
    }
};

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        // 定义一个指针来遍历
        TreeNode* cur = root;
        while(cur!=nullptr || !st.empty()){
            if(cur!=nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();     // 回退
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};



// 标记迭代法----在要处理的结点入栈后，放入一个空指针作为标记
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();       // 将结点弹出，避免重复操作，下面再将右中左结点入栈
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if(node->left) st.push(node->left);
            }else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};