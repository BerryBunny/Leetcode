class Solution {
    public int compareVersion(String version1, String version2) {
        String s1[]=version1.split("\\.");
        String s2[]=version2.split("\\.");
        int maxlength=Math.max(s1.length,s2.length);
        for(int i=0; i<maxlength; i++)
        {
            int v1,v2;
            if(i<s1.length)  v1=Integer.parseInt(s1[i]);
            else v1=0;
            if(i<s2.length)  v2=Integer.parseInt(s2[i]);
            else v2=0;
            if(v1<v2) return -1;
            else if(v1>v2) return 1;
        }
        return 0;

    }
}
