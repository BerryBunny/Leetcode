class Solution {
public:
    string decodeString(string s) {
      stack<char> decode;
      int n=s.length();
      for(auto i:s)
      {
          if(i!=']')
          {
              decode.push(i);
          }
          else
          {
          string curr="";
          while(decode.top()!='[')
          {
              curr=decode.top()+curr; //get the code in one[]
              decode.pop();
          }
          decode.pop();//pop'['
          string number="";
          while(!decode.empty() and isdigit(decode.top()))
          {
           number=decode.top()+number;
           decode.pop();
          }
          int index=stoi(number);
          while(index--)
          {
              for(auto j:curr)
              {
                  decode.push(j);
              }
          }
          }
      }
        string result="";
        while(!decode.empty())
        {
            result=decode.top()+result;
            decode.pop();
        }
        return result;
    }
};

