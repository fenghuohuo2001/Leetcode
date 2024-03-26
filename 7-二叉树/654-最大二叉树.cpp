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
    TreeNode* traversal(vector<int> nums){
        // �ݹ���ֹ
        if(nums.size() == 0) return nullptr;
        // Ҷ�ӽڵ�
        TreeNode* node = new TreeNode(0);
        if(nums.size() == 1){
            node->val = nums[0];
            return node;
        } 
        // ����ݹ�
        int maxValue = 0;
        int maxValueIndex = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;
        // ȷ����������ֵ
        if(maxValueIndex>0){
            vector<int> newVecLeft(nums.begin(), nums.begin() + maxValueIndex);
            node->left = traversal(newVecLeft);
        }
        // ȷ����������ֵ
        if(maxValueIndex<nums.size()-1){
            vector<int> newVecRight(nums.begin()+maxValueIndex+1, nums.end());
            node->right = traversal(newVecRight);
        }
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums);
    }
};