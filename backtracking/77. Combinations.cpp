class Solution {
public:
    void dfs(vector<vector<int>> & res, vector<int> cur, int n, int k,int idx)
    {
       if(cur.size()==k)
       {
          res.push_back(cur);
          return;
        }
       for(int i=idx; i<=n;i++)
       {
          cur.push_back(i);
          dfs(res, cur, n, k,i+1);
          cur.pop_back();
        }
     }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res,cur,n,k,1);
        return res;
    }
};
