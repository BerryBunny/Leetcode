class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
       unordered_map<char, int> dictionary;
        int n = order.size();
        int len = words.size();
        for(int i = 0; i < n; ++i)
        {
            dictionary[order[i]] = i;
        }
        
        for(int i = 0; i < len - 1; i++)
        {
            int pointer1 = 0;
            int pointer2 = 0;
            int compare_val = 0;
            string str1 = words[i];
            string str2 = words[i+1];
            int len1 = str1.size();
            int len2 = str2.size();
            while(pointer1 < len1 && pointer2 < len2 && compare_val == 0)
            {
                int x = dictionary[str1[pointer1]];
                int y = dictionary[str2[pointer2]];
                compare_val = x - y;
                if(compare_val > 0) return false;
                pointer1++;
                pointer2++;
               
            }
            if(compare_val == 0)
            {
                if(len1 > len2) return false;
                else return true;
            }
        }
        return true;
    }
};