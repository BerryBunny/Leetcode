
//iterative solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};
        vector<vector<int>> result={{}};
        for(int i:nums){
           int n=result.size();
            for(int j=0;j<n;j++){
                vector<int> currvec=result[j];
                currvec.push_back(i);
                result.push_back(currvec);
    }
        }
        return result;
    }
};


//Recursion solution

class Solution {
    void recur_sub(vector<int> &nums, int index, vector<vector<int>> & result) {
        if(index == nums.size()-1){
            result.push_back({});
            result.push_back({nums[index]});
        }
        else{
            recur_sub(nums,index+1,result);
            int n = result.size();
            for(int i = 0; i< n; i++){
                vector<int> temp=result[i];
                temp.push_back(nums[index]);
                result.push_back(temp);
            }
        }

    }
public:

   vector<vector<int>> subsets(vector<int>& nums) {
    if(nums.empty()) return {{}};
    vector<vector<int>> result;
    recur_sub(nums,0,result);
    return result;
   }

};
