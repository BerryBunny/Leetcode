class Solution {

public:
    string frequencySort(string s) {
       unordered_map<char,int> hash;//use hashmap to count how many times the characters appeared in the string
        for(auto i:s)
        {
            hash[i]++;
        }
        sort(s.begin(),s.end(),[&hash](char a,char b)
             {
                 return hash[a]>hash[b] || (hash[a]==hash[b] && a>b);
             });//this is to make sure the higher frequency characters show first;
        return s;
    }
};


class Solution{
public:
   string frequencySort(string s){
    vector<int> temp(128,0);
    for(char c:s) temp[c]++;
    vector<pair<int,char>> v;
    for(int i=0; i<128; ++i)
    {
        if(temp[i]>0) v.emplace_back(temp[i],i);
    }
    string result;
    sort(v.rbegin().v.rend());
    for(auto kv:v)
    {
        result.append(v.first,v.second);
    }
    return result;
   }
};
