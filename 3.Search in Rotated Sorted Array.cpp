//3.serach in rotated sorted linkdlist
class Solution {
public:
    int search(vector<int>& nums, int target) {

      int left=0;
      int right=nums.size()-1;
      while(left<right){
          int pivot=left+(right-left)/2;
          if(nums[pivot] > nums[right]){
              left=pivot+1;
          }else{
              right=pivot;
          }
      }
      //this loop will break when left get the smallest number
      //use binary search

      int start = left;
      left = 0;
      right = nums.size()-1;
      if(target>=nums[start]&&target<=nums[right]){
          left=start;
      } else{
          right=start;
      }

      while(left<=right){
          int pivot=left+(right-left)/2;
          if(nums[pivot]==target) return pivot;
          else if(nums[pivot]<target){
              left=pivot+1;
          }
          else{
              right=pivot-1;
          }
      }
      return -1;
    }

};







  int temp=nums.size();
      if(temp==0) {return -1;}
      int left=0;
      int right=temp-1;
      int start=nums[0];
      while(left<=right){
          int mid=left + (left-right)/2;
          int value = nums[mid];
          if(target == value) {return mid;}
          bool mid_big= value>=start;
          bool target_big= target>=start;
          if(mid_big==target_big){
              if(value < target){
                  left=mid+1;
              }else{
                  right=mid-1;
              }
          }
          else{
          if(mid_big){
              left=mid+1;
          }else{
              right=mid-1;
          }
          }

      }

    return -1;
    }


