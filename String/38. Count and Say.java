class Solution {
    public String countAndSay(int n) {
        String result = "1";
        for(int i = 1; i < n; i++)
        {
            StringBuilder sb = new StringBuilder();
            int count = 0;
            char start = result.charAt(0);
            for(int j = 0; j < result.length(); j++)
            {
                if(start == result.charAt(j))
                {
                    count++;
                }
                else
                {
                    sb.append(count).append(start);
                    count = 1;
                    start = result.charAt(j);
                }
            }
            sb.append(count).append(start);
            result = sb.toString();
        }
        return result;
    }
}
