class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
       List<String> result = new ArrayList<>();
       int i = 0;
       
        while (i < currentState.length())
        {
            int currentIndex = currentState.indexOf("++", i);
            
            if(currentIndex == -1)
            {
                return result;
            }
            
            String temp = currentState.substring(0, currentIndex) + "--" + currentState.substring(currentIndex + 2);
            result.add(temp);
            i = currentIndex + 1;
        }
        
        return result;
    }
}