//cpp
class Solution {
public:
    string intToRoman(int num) {
     vector<int> integers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
     vector<string> romans = {"M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
     string result;
     for(int i = 0; i < integers.size(); i++)
     {
         while(num >= integers[i])
         {
             num -= integers[i];
             result += romans[i];
         }
     }
   
        return result;
    }
};

//java

class Solution {
    public String intToRoman(int num) {
     int integers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
     String romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
     StringBuilder sb = new StringBuilder();
     for(int i = 0; i < integers.length; i++)
     {
         while(num >= integers[i])
         {
             num -= integers[i];
             sb.append(romans[i]);
         }
     }
        return sb.toString();
        
    }
}
