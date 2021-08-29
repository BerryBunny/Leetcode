class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      for (auto i:nums)
      {
          int index=abs(i)-1;
          nums[index] *=-1;
          if(nums[index]>0)
          {
              return abs(i);
           }
       }
        return 0;
    }
};
//when I mark a number as visited, it is multiplied by -1. Since -ve index is not acceptable |nums[i]| is taken.
// TC: O(N), SC: O(1)
    /*
        Since the numbers are [1:N], so we use the array indices for storing the
        visited state of each number, only the duplicate will be visited twice.
        For each number we goto its index position and multiply by -1. In case
        of duplicate it will be multiplied twice and the number will be +ve.
    */

int sortingSolution(vector<int>& nums) {
        // sort the numbers and find the number which has duplicate
        // by checking the one which has the same at next position
        sort(nums.begin(), nums.end());
        
        int duplicate = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i+1]) {
                duplicate = nums[i];
                break;
            }
        return duplicate;
    }
