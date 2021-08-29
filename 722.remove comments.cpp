class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
      vector<string> res;
      string s;
      int n=source.size();
      bool is_comment=false;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<source[i].size();j++)
          {
              if(!is_comment and j+1<source[i].size() and source[i][j]=='/' and source[i][j+1]=='/')
              {
                  break;
              }
              else if(!is_comment and j+1<source[i].size() and source[i][j]=='/' and source[i][j+1]=='*')
              {
                  is_comment=true;
                  j++;
              }
              else if(is_comment and j+1<source[i].size() and source[i][j]=='*' and source[i][j+1]=='/')
              {
                  is_comment=false;
                  j++;
              }
              else if(!is_comment)
                  s.push_back(source[i][j]);
          }
          if(!is_comment and s.size())
          {
          res.push_back(s);
          s.clear();
          }
      }
        return res;
    }
};
