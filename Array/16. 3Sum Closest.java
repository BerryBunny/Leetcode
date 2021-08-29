class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int result = nums[0] + nums[1] + nums[nums.length - 1];
        Arrays.sort(nums);//[-4,-1,1,2]
       // int diff = Integer.MAX_VALUE;
        
        for(int i = 0; i < nums.length - 2; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.length - 1;
            
            while(left < right)
            {
                int curr_sum = nums[i] + nums[left] + nums[right];
                if(curr_sum > target) right--;
                else if(curr_sum < target) left++;
                else return curr_sum;
                
                if(Math.abs(result - target) > Math.abs(curr_sum - target) )
                {
                   // diff = Math.abs(curr_sum - target);
                    result = curr_sum;
                }
             }
        }
        return result;
        
    }
}