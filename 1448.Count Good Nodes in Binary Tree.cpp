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
    int dfs(TreeNode* root, int max_val)
    {
       max_val=max(root->val,max_val);
       int result =root->val >= max_val ? 1:0;
       if(root->left)
           result+= dfs(root->left,max_val);
       if(root->right)
           result+= dfs(root->right,max_val);

        return result;
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return dfs(root,-10000);

    }
};
