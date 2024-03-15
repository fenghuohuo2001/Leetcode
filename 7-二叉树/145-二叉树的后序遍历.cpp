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
        traversal(cur->right, _result);
        _result.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

#include <stack>
class Solution{
private:
    vector<int> reverse(vector<int> &_result){
        for(int i=0, j=_result.size()-1; i<j; i++, j--){
            swap(_result[i], _result[j]);
        }
        return _result;
    }
public:
    // ��������� ������ ��ǰ������Ļ�����(������->������)����ת�������
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root == nullptr) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* midnode = st.top();
            st.pop();
            result.push_back(midnode->val);
            if(midnode->left) st.push(midnode->left);
            if(midnode->right) st.push(midnode->right);
        }
        vector<int> final_result = reverse(result); 
        return final_result;
    }
};


class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != nullptr) {
                st.pop();       // ����㵯���������ظ������������ٽ�����������ջ
                st.push(node);
                st.push(nullptr);   // ���н���ӱ�־
                if(node->right) st.push(node->right);
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