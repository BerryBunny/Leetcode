//O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.size()==0)  return 0;
       int result=INT_MIN;
        vector<int>idx(128,-1);
       for(int left=0,right=0; right<s.size(); right++)
       {
          left=max(left,idx[s[right]]+1);
          result=max(result,right-left+1);
          idx[s[right]]=right;
        }
        return result;
    } 
};

//O(logN)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.size()==0)  return 0;
        int a_pointer=0;//this is the start pointer;
        int b_pointer=0;//this is the pointer that will iterate the string;
        int maxsize=INT_MIN;
        unordered_set<char>hash;
        while(b_pointer<s.size())
        {
            if(hash.count(s[b_pointer])==0)
               {
                   hash.insert(s[b_pointer]);
                   b_pointer++;
                   maxsize=max(maxsize,(int)hash.size());
                }
               else
               {
                   hash.erase(s[a_pointer]);
                   a_pointer++;
                }
        }
               return maxsize;
    }
};
