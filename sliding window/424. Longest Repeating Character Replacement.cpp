class Solution {
public:
    int characterReplacement(string s, int k) {
       int n=s.size();
       int window_start=0;
       int max_counts=INT_MIN;
       int max_length=INT_MIN;
       vector<int> char_counts(128,0);
     for (int window_end=0; window_end<n; window_end++)
     {
        char_counts[s[window_end]]++;
        int curr_counts=char_counts[s[window_end]];
        max_counts=max(max_counts,curr_counts);
        while(window_end-window_start+1-max_counts>k)
        {
            char_counts[s[window_start]]--;
            window_start++;
         }
         max_length=max(max_length,window_end-window_start+1);
      }
        return max_length;
    }
};
