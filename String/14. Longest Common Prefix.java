class Solution {
    public String longestCommonPrefix(String[] strs) {
      String result = strs[0];
      if(strs.length == 0) return "";
      for(int i = 0; i < strs.length; ++i)
      {
          while(!strs[i].startsWith(result))
          {
              result = result.substring(0, result.length() - 1);
          }
      }
        return result;
    }
}
