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
        vec.push_back(cur->val);        // ��
        traversal(cur->left, vec);      // ��
        traversal(cur->right, vec);     // ��
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
    
};


// ǰ�����
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
        // ��
        _result.push_back(cur->val);
        // ��
        traversal(cur->left, _result);
        // ��
        traversal(cur->right, _result);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

#include <stack>

/* ������ ǰ�����*/
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

// ��������
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        // ��rootΪ�գ�ֱ��return
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()){
            // ����С�Ķ�������������ǰ����������
            // ȡ�н��
            TreeNode* mid_node = st.top();
            // �г�ջ��������
            st.pop();
            result.push_back(mid_node->val);
            // ���ҽ�㲻Ϊ�գ���ջ
            if(mid_node->right) st.push(mid_node->right);
            // �����㲻Ϊ�գ���ջ
            if(mid_node->left) st.push(mid_node->left);
        }
        return result;
    }
};


// ��ǵ�����----��Ҫ����Ľ����ջ�󣬷���һ����ָ����Ϊ���
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();       // ����㵯���������ظ������������ٽ������н����ջ
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