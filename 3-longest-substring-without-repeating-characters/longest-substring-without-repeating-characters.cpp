class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0, end = 0;
        int len = 0;
        unordered_map<char, int> freq;
        while (end < n) {
            freq[s[end]]++;
            while (freq[s[end]] > 1) {
                freq[s[start]]--;
                start++;
            }
            len = max(len, end - start + 1);
            end++;
        }
        return len;
    }
};