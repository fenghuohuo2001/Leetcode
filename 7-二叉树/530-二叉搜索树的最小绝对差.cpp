#include <vector>
#include <limits>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 中序遍历转数组排序 计算min abs_diff
class Solution {
public:
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root==nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        int minabsdiff = numeric_limits<int>::max();
        
        for(int i=0; i<vec.size()-1; i++){
            int diff = abs(vec[i+1]-vec[i]);
            if(diff<minabsdiff) minabsdiff=diff;
        }
        return minabsdiff;
    }
};