#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _x): val(_x), left(nullptr), right(nullptr) {}
};

// �ݹ�д��
class Solution{
public:
    // ������ƽ���������ʱ�򣬾Ͳ����ظ߶��ˣ�ֱ�ӷ���-1
    int getHeight(TreeNode* node){
        if(node==nullptr) return 0;     // �սڵ�ĸ߶�Ϊ0
        // ��ȡ������
        int leftheight = getHeight(node->left);
        if(leftheight==-1) return -1;
        // ��ȡ������
        int rightheight = getHeight(node->right);
        if(rightheight==-1) return -1;

        // �����ֵ
        int result = 0;
        if(abs(leftheight - rightheight) > 1) result = -1;
        else result = 1 + max(leftheight, rightheight);     // �ڵ�߶����������߶� 

        return result;
    }

    bool isBalanced(TreeNode* root){
        return getHeight(root) == -1 ? false : true;
    }
};


class Solution{
public:
    int getHeight(TreeNode* node){
        if(node == nullptr) return 0;

        int left_height = getHeight(node->left);
        if(left_height == -1) return -1;

        int right_height = getHeight(node->right);
        if(right_height == -1) return -1;

        int result;
        if(abs(left_height-right_height) > 1) result = -1;
        else result = 1 + max(left_height, right_height);
        return result;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1? false : true; 
    }
};