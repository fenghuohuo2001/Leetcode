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
    // ��������� ������
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
// ������
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        // ���������������
        while(cur != nullptr || !st.empty()){
            if(cur!=nullptr){
                st.push(cur);
                cur = cur->left;        // �����������㣬 ����һ����nullptr�򲻻���ջ
            }else{
                cur = st.top();         // ȡ������
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;       // ��һ�ε�right���ҲΪ�գ����ȡ�н��
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
        // ����һ��ָ��������
        TreeNode* cur = root;
        while(cur!=nullptr || !st.empty()){
            if(cur!=nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();     // ����
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};



// ��ǵ�����----��Ҫ����Ľ����ջ�󣬷���һ����ָ����Ϊ���
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();       // ����㵯���������ظ������������ٽ�����������ջ
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