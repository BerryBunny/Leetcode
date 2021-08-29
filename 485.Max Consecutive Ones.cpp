class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result=0;
        int maxresult=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
            {result++;
                if(result>maxresult)
                {
                maxresult=result;
                }
            }
            else result=0;

        }
        return max(result,maxresult);
    }
};
