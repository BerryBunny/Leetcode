class Solution {
    public int lengthOfLastWord(String s) {
        if(s == null || s.length() == 0) return 0;
        String s1 = s.trim();
        int last = s1.lastIndexOf(" ");
        int n = s1.length();
        String str = s1.substring(last + 1, n);
        return str.length() ;
    }
}

//lower level
class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length() - 1;
        int result = 0;
        while( n >= 0 && s.charAt(n) == ' ')
        {
            n--;
        }
        if( n == -1) return 0;
        while(n >= 0 && s.charAt(n) != ' ')
        {
            result++;
            n--;
        }
        return  result;
    }
}
