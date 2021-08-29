class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //assume a + b > c
        //a <= b <= c
        int n = nums.size();
        if(n < 3) return 0;
        std::sort(nums.rbegin(), nums.rend());
        int count = 0;
        for(int c = 0; c < n - 2; c++)
        {
            int a = n - 1;
            int b = c + 1;
            while(a > b)
            {
                if(nums[a] + nums[b] > nums[c])
                {
                    count += a - b;
                    b++;
                }
                else 
                    a--;
            }
        }
        return count;
    }
};