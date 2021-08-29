class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.isEmpty()) return 0;        
        if(haystack.startsWith(needle)) return 0;
        int n = needle.length();//2
        int low = haystack.indexOf(needle.charAt(0));//2
        if(low == -1) return -1;
        for(int i = low; i < haystack.length(); i++)
        {
            StringBuilder sb = new StringBuilder();
            if (i + needle.length() > haystack.length()) break;
            for (int j = 0; j < needle.length(); j++)
            {
                if(haystack.charAt(i+j) == needle.charAt(j))
                {
                    sb.append(needle.charAt(j));
                }
                else
                {
                    break;
                }
               
            }
              String temp = sb.toString();
              if(temp.equals(needle)) return i;
        }
        return -1;
    }
}
