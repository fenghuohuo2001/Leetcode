#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _x): val(_x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // ����洢����
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if(root != nullptr) que.push(root);

        while(!que.empty()){
            // ÿ��Ҫ���³�ʼ��size��ֵ����Ϊsize�ڲ��ϱ仯
            int size = que.size();
            vector<int> vec;
            for(int i=0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};