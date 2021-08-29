class Solution {
    unordered_map<string, string> email_to_name;
    unordered_map<string, vector<string>> email_to_root;
    set<string> visited;
private:
    void helper(string email, set<string> &emails)
    {
        if(visited.find(email) != visited.end())
            return;
        
        visited.insert(email);
        emails.insert(email);
        for(auto root : email_to_root[email])
            helper(root, emails);
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       vector<vector<string>> result;
        for(auto account : accounts)
        {
            string name = account[0];
            string father = account[1];
            email_to_name[father] = name;
            int n = account.size();
            
            for(int i = 1; i < n; ++i)
            {
                string email = account[i];
                email_to_root[father].push_back(email);
                email_to_root[email].push_back(father);
                email_to_name[email] = name;
            }
        }
        
        for(auto x : email_to_root)
        {
            string email = x.first;
            if(visited.find(email) == visited.end())
            {
            set<string> emails;
            helper(email, emails);
            string name = email_to_name[email];
            vector<string> temp;
            temp.push_back(name);
            for(auto root : emails)
                temp.push_back(root);
            
            result.push_back(temp);
            }
        }
        return result;
    }
};
