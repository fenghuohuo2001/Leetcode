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
    void traversal(TreeNode* cur, vector<int> &vec){
        if(cur == NULL) return;
        vec.push_back(cur->val);        // 中
        traversal(cur->left, vec);      // 左
        traversal(cur->right, vec);     // 右
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
    
};


// 前序遍历
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _x): val(_x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    void traversal(TreeNode* cur, vector<int> &_result){
        if(cur == nullptr) return;
        // 中
        _result.push_back(cur->val);
        // 左
        traversal(cur->left, _result);
        // 右
        traversal(cur->right, _result);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

#include <stack>

/* 迭代法 前序遍历*/
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return result;
    }
};

// 迭代遍历
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        // 若root为空，直接return
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()){
            // 用最小的二叉树作分析，前序是中左右
            // 取中结点
            TreeNode* mid_node = st.top();
            // 中出栈，入数组
            st.pop();
            result.push_back(mid_node->val);
            // 若右结点不为空，入栈
            if(mid_node->right) st.push(mid_node->right);
            // 若左结点不为空，入栈
            if(mid_node->left) st.push(mid_node->left);
        }
        return result;
    }
};


// 标记迭代法----在要处理的结点入栈后，放入一个空指针作为标记
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();       // 将结点弹出，避免重复操作，下面再将右左中结点入栈
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr);
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