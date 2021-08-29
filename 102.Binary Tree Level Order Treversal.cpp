//DFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty())
        {
           int length=temp.size();
            vector <int> store;
            while(length>0)
            {
              TreeNode *cur=temp.front();
               temp.pop();
               store.push_back(cur->val);
               if(cur->left)
               {
                   temp.push(cur->left);
               }
               if(cur->right)
               {
                   temp.push(cur->right);
               }
               length=length-1;
            }
            result.push_back(store);
        }
        return result;
    }
};

//BFS
class Solution {
    void dfs(TreeNode* cur, int depth, vector<vector<int>>& r)
    {
        if(!cur) return;
        if(r.size()==depth)
        {
            r.push_back({});
        }
        if(cur)
        {
            r[depth].push_back(cur->val);
        }
        if(cur->left) dfs(cur->left, depth + 1, r);
        if(cur->right) dfs(cur->right, depth + 1, r);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
       vector<vector<int>> result;
       dfs(root,0,result);
       return result;
    }
};
