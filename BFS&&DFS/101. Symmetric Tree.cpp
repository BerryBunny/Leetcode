/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> s1, s2;
        s1.push(root->left);
        s2.push(root->right);
        while(!s1.empty() && !s2.empty()){
            TreeNode* x1 = s1.top(); s1.pop();
            TreeNode* x2 = s2.top(); s2.pop();
            if(!x1 && !x2) continue;
            if(!x1 || !x2 || x1->val!=x2->val) return false;
            s1.push(x1->left); s1.push(x1->right);
            s2.push(x2->right); s2.push(x2->left);
        }
        if(s1.size() == s2.size()) return true;
        else return false;
        
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* q, TreeNode* p)
    {
        if(!q and !p) return true;
        if(!q or !p) return false;
        if(q->val != p->val) return false;
        return helper(q->left, p->right) and helper(q->right, p->left);
     }

};
