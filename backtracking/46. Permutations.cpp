class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &nums, vector<int> &permutations, vector<bool>& visited)
    {
        if(permutations.size()==nums.size())
        {
            res.emplace_back(permutations);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(!visited[i])
            {
               visited[i]=true;
               permutations.emplace_back(nums[i]);
               backtrack(res,nums,permutations,visited);
               visited[i]=false;
               permutations.pop_back();
             }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool>visited(nums.size(),0);
        vector<int> permutations;
        backtrack(res,nums,permutations,visited);
        return res;
    }
};
