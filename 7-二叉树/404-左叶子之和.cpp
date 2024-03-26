#include <vector>
#include <string>
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
    int sumOfLeftLeaves(TreeNode* root) {
        // �ݹ� �������
        if(root == nullptr) return 0;       // �սڵ����Ҷ�ӽڵ�Ϊ0
        // ����Ҷ�ӽڵ㣬����Ҷ�ӽڵ�ҲΪ0
        if(root->left==nullptr && root->right==nullptr) return 0;
        // ���������е�˳�����
        int leftValue = sumOfLeftLeaves(root->left);    // ��
        // �ж���Ҷ�ӽڵ�
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            leftValue = root->left->val;
        }   // ��
        int rightValue = sumOfLeftLeaves(root->right);      // ��
        return leftValue + rightValue;
    }
};