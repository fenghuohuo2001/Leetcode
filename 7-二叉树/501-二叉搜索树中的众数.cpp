#include <vector>
#include <unordered_map>
#include <algorithm>
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
    void searchBST(TreeNode* cur, unordered_map<int, int>&map){
        if(cur == nullptr) return;
        map[cur->val]++;
        searchBST(cur->left, map);
        searchBST(cur->right, map);
        return;
    }

    bool static cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> result;
        if(root == nullptr) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        result.push_back(vec[0].first);
        for(int i=1; i<vec.size(); i++){
            if(vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};


class Solution {
public:
    // 使用map统计出现频率
    void searchBST(TreeNode* root, unordered_map<int, int> &map){
        if(root==nullptr) return ;
        map[root->val]++;
        searchBST(root->left, map);
        searchBST(root->right, map);
    }

    // 降序排序，递减
    bool static cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        unordered_map<int, int> map;
        if(root == nullptr) return result;
        searchBST(root, map);
        // map无法排序 因此需要将map转为vector
        vector<pair<int, int>> vec(map.begin(), map.end());     // val - frequency
        sort(vec.begin(), vec.end(), cmp);
        // 将第一个放入
        result.push_back(vec[0].first);
        
        // 排序好之后进行遍历
        for(int i=1; i<vec.size(); i++){
            if(vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;         // 提前结束
        }
        return result;
    }
};