class Solution {
public:
     vector<vector<int>> _graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       _graph=vector<vector<int>> (numCourses);
       for(auto x:prerequisites)
       {
          _graph[x[0]].push_back(x[1]); 
        }
       
       vector<int> check(numCourses,0);
        // state 0 means unknown; state 1 means visiting, state 2 means visited;
       for(int i=0; i<numCourses; i++)
       {
           if (cycle(i, check)) return false;
       }
        return true;
    }
    
     bool cycle(int cur, vector<int> &check)
     {
        if (check[cur]==1) return true;
        if (check[cur]==2) return false;
        check[cur] =1;
        for(auto x:_graph[cur])
        {
           if(cycle(x, check) == true) return true; 
         }
       check[cur] =2;
         
        
         return false;
      }
    
};
