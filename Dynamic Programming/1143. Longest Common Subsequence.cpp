/*
using a dp array to store the anwser;
i is the pointer pointing to the ending position of A
j is the pointer pointing to the ending position of B

so if text1[i] == text2  we can make sure that there must be 1 commen sequence;
but if not, you need to find the commen either before position i from A or before position j from B

XXXXXX i;
YYYYYYYYYY j;
*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        text1 = "/" + text1;
        text2 = "/" + text2;
        auto dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        int result = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[i] == text2[j])
                {
                  dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                 result = max(result, dp[i][j]);
            }
            
         }
        
        return result;
    }
};