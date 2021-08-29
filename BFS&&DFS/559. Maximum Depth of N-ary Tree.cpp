/*
// Definition for a Node.
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
*/

class Solution {
public:
    int max_depth=INT_MIN;
    int maxDepth(Node* root) {
       if(root == nullptr) return 0;
       helper(root, 1);
       return max_depth;
    }
    void helper(Node* node, int depth)
    {
       if (node == nullptr) return;
      // max_depth=max(depth, max_depth);
       for (auto child : node->children) helper(child, depth+1);
        max_depth=max(depth, max_depth);
    }
};


class Solution {
public:
    int max_depth=INT_MIN;
    int maxDepth(Node* root) {
       if(root == nullptr) return 0;
       helper(root, 1);
       return max_depth;
    }
    void helper(Node* node, int depth)
    {
       if (node == nullptr) return;
       max_depth=max(depth, max_depth);
       for (auto child : node->children) helper(child, depth+1);
    }
};
