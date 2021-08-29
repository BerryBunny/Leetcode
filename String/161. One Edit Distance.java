class Solution {
    public boolean isOneEditDistance(String s, String t) {
        if (Math.abs(s.length() - t.length()) > 1 || s.equals(t)) return false;
        
        if(s.length() < t.length())
        {
            String temp = s;
            s = t;
            t = temp;
        }
        
        for(int i = 0; i < t.length(); ++i)
        {
            if(s.charAt(i) != t.charAt(i))
                //two cases, if s.length()==t.length() or s.length() > t.length
            {
            if(s.length() == t.length())
                return s.substring(i+1).equals(t.substring(i+1));
            
            if(s.length() > t.length())
                return s.substring(i+1).equals(t.substring(i));
            }
        }
        
        
        return true;
        
        
    }
}