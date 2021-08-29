//O(n) space solution
class Solution {
public:
    int trap(vector<int>& height) {
      //first we use two vectors to store maxleft and maxright;
        int n=height.size();
        if(n<=2) return 0;
      vector<int> left(n),right(n);
      int result=0;
      int maxleft=height[0];
      left[0]=0;
      right[n-1]=0;
      int maxright=height[n-1];
      for(int i=1;i<n;i++)
      {
          left[i]=maxleft;
          maxleft=max(maxleft,height[i]);
      }

      for(int i=n-2;i>=0;i--)
      {
          right[i]=maxright;
          maxright=max(maxright,height[i]);
      }

      for(int i=1;i<n-1;i++)
      {
      if(height[i]<left[i] and height[i]<right[i])
      {
          result=result+(min(left[i],right[i])-height[i]);
      }
      }
        return result;
    }
};

//O(1) space solution;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2) return 0;
      int result=0;
      int maxleft=height[0];
      int maxright=height[n-1];
      int left=1;
      int right=n-2;
      while(left<=right)
      {
          if(maxleft<maxright)
          {
              if(maxleft<=height[left])
              {
                  maxleft=height[left];
              }
              else result=result+(maxleft-height[left]);
              left++;
          }
          else
          {
             if(maxright<=height[right])
             {
                 maxright=height[right];
             }
              else result=result+(maxright-height[right]);
              right--;
          }
      }
        return result;
    }
};

