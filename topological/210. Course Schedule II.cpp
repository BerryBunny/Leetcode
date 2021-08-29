class Solution {
public:
    vector<vector<int>> _graph;
    vector<int> result;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     _graph=vector<vector<int>>(numCourses);
     for(auto p: prerequisites)
     {
        _graph[p[1]].push_back(p[0]);
      }
     vector<int> check(numCourses, 0);
        for(int i=0; i < numCourses; i++)
        {
            if (helper(i, check, result)) return {};
         }
        reverse(result.begin(), result.end());
        return result;
    }

    bool helper(int cur, vector<int> &check, vector<int> &result)
    {
        if(check[cur] == 1) return true;
        if(check[cur] == 2) return false;
        check[cur] = 1;
        for(auto x: _graph[cur])
        {
            if(helper(x, check, result)) return true;
         }
        check[cur] =2;
        result.push_back(cur);
        return false;
    }


};
