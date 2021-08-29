class Solution {
    unordered_map<string, int> hash;
private:
    int ways(const string &s)
    {
        if(hash.count(s)) return hash[s];
        if(s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        
        int counts = ways(s.substr(1));
        if((s[0] - '0') * 10 + (s[1] - '0') <=26)
            counts += ways(s.substr(2));
        hash[s] = counts;
        return counts;
    }
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        hash[""] = 1;
        return ways(s);
        
        
    }
};
