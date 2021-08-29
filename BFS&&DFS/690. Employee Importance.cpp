/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
// author Berry
// bfs
class Solution {
public:
    int sum=0;
    int getImportance(vector<Employee*> employees, int id) {
       int n =employees.size();
        if( n == 0) return 0;
        unordered_map<int, Employee*> hash;
        for(auto i:employees)
        {
            hash[i->id]= i;
        }
        queue<Employee*> q;
        q.push(hash[id]);
        while(!q.empty())
        {
           Employee* curr=q.front();
           q.pop();
           sum += curr->importance;
           for(auto n : curr->subordinates) q.push(hash[n]);
        }
         return sum;
    }
};

class Solution {
public:
    int sum=0;
    int getImportance(vector<Employee*> employees, int id) {
       int n= employees.size();
       unordered_map<int, Employee*> hash;
       for(auto employee: employees)
       {
          hash[employee->id] = employee;
        }
       helper(hash, id, sum);
       return sum;
    }
    void helper(unordered_map<int, Employee*> hash, int id, int &sum)
    {
        sum += hash[id]->importance;
        for(auto x: hash[id]->subordinates) helper(hash, x,sum );
    }
};
