
//brute force;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       const int n = nums.size();
        if(n == 0 or n == 1) return 1;
       vector<int> dp = vector<int>(n, 1);
        int count = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            count = max(count, dp[i]);
        }
        return count;
    }
};

/*Patience Sorting

For two subsequence of the same length, like [1,2,3] and [3,4,5]
Apperantly, [1,2,3] is better because we can expand more based on 3;

What about [1,2,5] and [3,4,5] ? They are the same to the following numbers at length 3;
but [1,2,5] is better at length 2;

dp[i] = the smallest ending number of a subsequence that has length i + 1 ;

Init; dp = [];

For each num, we can use it to:
1. extand the longest subsequence;
2. replace the number to generate a bettter sequence;

dp is increasing, we can use binary search to find the position to insert it.

num      dp 
 3      [3] //[3]
 4     [3,4] //[3], [*,4]
 1     [1,4] //[1], [*,4]
 2     [1,2] //[1], [*,2]
 8     [1,2,8] //[1], [*,2],[*,*,8]
 5     [1,2,5] //[1],[*,2],[*,*,5]
 6    [1,2,5,6] //[1],[*,2],[*,*,5] [*,*,*,6]
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      const int n = nums.size();
        vector<int> dp;
        for(int x : nums)
        {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if(it == dp.end())
            {
                dp.push_back(x);
            }
            else
            {
                *it = x;
            }
        }
        
        return dp.size();
    }
};
//Time complexity : O(nlogn)
//Space complexity : O(n)


