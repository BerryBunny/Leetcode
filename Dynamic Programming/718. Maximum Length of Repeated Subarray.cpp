/*
the longgest subsequence
dp[i][j] : i stands for the end position of the subarray A, j means the end position of subarray B;
if you want to get the repeated subarray, then you need to make the next statement is dp[i-1][j-1];
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);
        vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int> (n+1, 0));
        int result = 0;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    result = max(result, dp[i][j]);
                }
                 
            }
        }
        
        
        
        return result;
        
        
        
    }
};