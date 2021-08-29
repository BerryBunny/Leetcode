class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 4) return result;
        //check the corner case;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++)
        {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n - 2; j++)
            {
                if(j > i + 1 and nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = n - 1;
                while(l > k)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target)
                    {
                      l--;
                     while(nums[l] == nums[l+1] and l > k) l--;
                    }
                     else if(sum < target)
                    {
                      k++;
                     while(nums[k] == nums[k-1] and l > k) k++;
                    }
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        result.push_back(temp);
                        k++;
                        l--;
                        while(nums[l] == nums[l+1] and l > k) l--;
                        while(nums[k] == nums[k-1] and l > k) k++;
                    }
                }
            }
        }
        return result;
    }
};