class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(char c : t) {
            m[c]++;
        }

        int total = t.size();
        int start = 0, end = 0;
        int n = s.size();
        int ans = INT_MAX;
        int index = -1;

        while(end < n) {
            if(m[s[end]] > 0) {
                total--;
            }
            m[s[end]]--;

            while(total == 0) {
                if(ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }

                m[s[start]]++;
                if(m[s[start]] > 0) {
                    total++;
                }
                start++;
            }

            end++;
        }

        return index == -1 ? "" : s.substr(index, ans);
    }
};