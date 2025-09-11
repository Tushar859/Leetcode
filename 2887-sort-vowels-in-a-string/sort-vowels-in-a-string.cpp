class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
        
        // Step 1: extract vowels
        vector<char> vowelList;
        for (char c : s) {
            if (vowelSet.count(c)) {
                vowelList.push_back(c);
            }
        }
        
        // Step 2: sort vowels by ASCII
        sort(vowelList.begin(), vowelList.end());
        
        // Step 3: rebuild string
        int idx = 0;
        for (char &c : s) {
            if (vowelSet.count(c)) {
                c = vowelList[idx++];
            }
        }
        
        return s;
    }
};
