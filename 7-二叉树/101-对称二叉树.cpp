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

// �������-�ݹ�-������
void post_traversal(TreeNode* cur, vector<int> &_result){
    if(cur == nullptr) return;
    post_traversal(cur->left, _result);
    post_traversal(cur->right, _result);
    _result.push_back(cur->val);
}

// �������-����-������
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


/* �����Էֽ�Ϊ�����������ڲ��Ƿ���� */
// �ݹ鷨
class Solution {
public:
    // ȷ���ݹ�����ͷ���ֵ
    bool compare(TreeNode* left, TreeNode* right){
        // ȷ����ֹ����
        if(left==nullptr && right!=nullptr) return false;
        else if(left!=nullptr && right==nullptr) return false;
        else if(left==nullptr && right==nullptr) return true;
        else if(left->val != right->val) return false;
        // �Ƚ�����Ƿ�Գ�
        bool outside = compare(left->left, right->right);
        // �Ƚ��ڲ��Ƿ�Գ�    
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


// ������
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
            // ���ж��Ƿ�Ϊ��
            if(leftnode==nullptr && rightnode==nullptr){
                continue;
            }
            
            if(leftnode==nullptr || rightnode==nullptr || (leftnode->val != rightnode->val)){
                return false;
            }
            // ������Ϊ�������ʱ
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
        // ���ж�root
        if(root == nullptr) return true;
        // ��д�ݹ�
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