class Solution {
public:
    string reverseWords(string s)
    {
      string result="";
      string temp;
      int n=s.size();
      for (int i =n-1; i>=0; i--)
      {

        if(s[i]==' ')
        {
            if(!temp.empty())
            {
                result=result+temp+' ';
                temp.clear();
            }
        }
         else
         temp=s[i]+temp;
      }
        result=result+temp;
        if(result[result.length()-1]==' ') result.erase(result.length()-1);
        return result;
    }
};
