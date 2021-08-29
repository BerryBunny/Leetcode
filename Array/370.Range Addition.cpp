//brute force -> time limit exceeded

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = updates.size();
        vector<int> result(length, 0);
        if(n <= 0) return result;
        
        for(auto update : updates)
        {
            int start = update[0];
            int end = update[1];
            int increment = update[2];
            for(int i = start; i <= end; i++)
            {
                result[i] += increment; 
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = updates.size();
        vector<int> result(length, 0);
        if(n <= 0) return result;
        
        for(auto update : updates)
        {
            int start = update[0];
            int end = update[1];
            int increment = update[2];
            result[start] += increment;
            if(end + 1 < length)
            {
                result[end + 1] -= increment;
            }
        }
        int sum = 0;
        for(int i = 0; i < length; i++)
        {
            sum += result[i];
            result[i] = sum;
        }
        return result;
    }
};


//The optimal time complexity is O(k + n) and uses O(1) extra space.