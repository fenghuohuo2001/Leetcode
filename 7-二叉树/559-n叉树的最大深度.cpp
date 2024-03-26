#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int getdepth(Node* node){
        if(node == nullptr) return 0;
        int depth = 0;
        for(int i=0; i<node->children.size(); i++){
            depth = max(depth, getdepth(node->children[i]));
        }
        return depth+1;
    }
    int maxDepth(Node* root) {
        return getdepth(root);
    }
};
