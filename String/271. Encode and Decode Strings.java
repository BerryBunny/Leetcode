public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        if(strs == null || strs.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        for(String str : strs)
        {
            sb.append(str.length()).append('/').append(str);
        }
        return sb.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
      List<String> result = new ArrayList<>();
      if(s == null || s.length() == 0) return result;
      
      int index = 0;
        while(index < s.length())
        {
            int slash = s.indexOf("/", index);
             //int length = Integer.valueOf(s.charAt(index));
             int length = Integer.valueOf(s.substring(index, slash));
            result.add(s.substring(slash + 1, slash + length + 1));
            index = slash + length + 1;
         }
        return result;
    }
}