// in this question, you need to set a string vector to store the elements in every row.
// for the first loop, we store the element vertically, and for the second loop, we store the elements diagonally;
//java
class Solution {
    public String convert(String s, int numRows) {

        char c[] = s.toCharArray();
        int length = c.length;
        StringBuilder sb[] = new StringBuilder[numRows];
        
        for(int i = 0; i < numRows; i++)
        {
            sb[i] = new StringBuilder();
        }
        
        int idx = 0;
        while(idx < length)
        {
            for(int i = 0; i < numRows && idx < length; i++)
            {
                sb[i].append(c[idx++]);
            }
            for(int i = numRows - 2; i >= 1 && idx < length; i--)
            {
                sb[i].append(c[idx++]);
            }
        }
        for(int i = 1; i < numRows; i++)
        {
            sb[0].append(sb[i]);
        }
        return sb[0].toString();
    }
}

//c++
class Solution {
public:
    string convert(string s, int numRows) {
      vector<string> container(numRows,"");
      int n = s.size();
      int idx = 0;
      while (idx < n)
      {
          for(int i = 0; i < numRows and idx < n; i++)
          {
              container[i].push_back(s[idx++]);
          }
          for(int i = numRows - 2; i >= 1 and idx < n; i--)
          {
              container[i].push_back(s[idx++]);
          }
      }
        string result;
        for(string v : container)
        {
            result += v;
        }
        return result;
    }
};
