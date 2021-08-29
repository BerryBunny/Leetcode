class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 3) return result;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++)
        {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            //implement binary search here;
            int left = i + 1;
            int right = n - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0)
                {
                    right--;
                    while(nums[right] == nums[right + 1] and left < right) right--;
                }
                else if(sum < 0)
                {
                    left++;
                    while(nums[left] == nums[left - 1] and left < right) left++;
                }
                else
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    right--;
                    left++;
                    while(nums[right] == nums[right + 1] and left < right) right--;
                    while(nums[left] == nums[left - 1] and left < right) left++;
                }
            }
        }
            return result;
    }
};