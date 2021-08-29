//recursion
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
      if(!root) return 0;
      int leftsum=rangeSumBST(root->left,low,high);
      int rightsum=rangeSumBST(root->right,low,high);
      int result=leftsum+rightsum;
      if(root->val >=low and root->val <=high)
      {
          result=result+root->val;
      }
        return result;

    }
};

//BFS
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
      if(!root) return 0;
      int result=0;
      queue<TreeNode*> temp;
      temp.push(root);
      while(!temp.empty())
      {
          int length=temp.size();
          TreeNode* dummy=temp.front();
          temp.pop();
          if(length>0)
          {
              if(dummy->val >=low and dummy->val <=high)
              {
                  result=result+dummy->val;
              }
              if(dummy->left)
              {
                  temp.push(dummy->left);
              }
              if(dummy->right)
              {
                  temp.push(dummy->right);
              }
              length=length-1;
          }
      }
        return result;
    }
};
