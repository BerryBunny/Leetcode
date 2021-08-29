//shifting pattern
//using a hashmap to solve this question
//map<String, List<String>>, key is to store the shift pattern, value is the string under this pattern
//"abc" -> (b-a = 1, c-b = 1) -> "1,1"
//"adf" -> (d-a = 3, f-d = 2) -> "3,2"
class Solution {
    private String helper(String word)
    {
        if(word == null || word.length() == 0) return "";
        if(word.length() == 1) return "/";
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < word.length() - 1; ++i)
        {
            int diff = word.charAt(i + 1) - word.charAt(i);
            if(diff < 0) diff += 26;
            sb.append(Integer.toString(diff) + "/");
        }
        return sb.toString();
    }
    public List<List<String>> groupStrings(String[] strings) {
        List<List<String>> result = new LinkedList<>();
        if(strings.length == 0)
            return result;
        
        Map<String, List<String>> patternOfWords = new HashMap<>();
        for(String word : strings)
        {
            String pattern = helper(word);
            if(!patternOfWords.containsKey(pattern))
            {
                patternOfWords.put(pattern, new LinkedList<String>());
            }
            patternOfWords.get(pattern).add(word);
        }
        
        for(String pattern : patternOfWords.keySet())
        {
            result.add(patternOfWords.get(pattern));
        }
        return result;
    }
}