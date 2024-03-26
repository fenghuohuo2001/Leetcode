#include <vector>
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return nullptr;

        // ���нڵ�
        int rootvalue = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootvalue);

        // ��Ҷ�ӽڵ�
        if(postorder.size() == 1) return root;

        // ���и��
        int index = 0;
        for(; index<inorder.size(); index++){
            if(inorder[index] == rootvalue) break;
        }

        // ���Ĳ����и��������飬�õ� ��������������������� 
        // ����ҿ�
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        // ���岽���и��������postorder���õ� ����������ͺ���������
        // �����нڵ�
        postorder.resize(postorder.size()-1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        // ����ݹ�
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};


class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        // ------------- �ݹ���ֹ���� --------------
        // �жϿսڵ�
        if(inorder.size() == 0) return nullptr;

        // �нڵ��ֵ
        int rootvalue = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootvalue);

        // �ж�Ҷ�ӽڵ�
        if(postorder.size() == 1) return root;
        
        // �ָ�����
        int index = 0;
        for(; index < inorder.size(); index++){
            if(inorder[index] == rootvalue) break;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());

        // �ָ����(������)
        postorder.resize(postorder.size()-1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());
        
        // ����ݹ�
        root->left = traversal(leftInorder,leftPostorder);
        root->right = traversal(rightInorder,rightPostorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};