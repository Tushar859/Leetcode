class Solution(object):
    def lengthOfLongestSubstring(self, s):
        n = len(s)
        st =0
        end =0
        freq ={}
        length =0
        while(end<n):
            freq[s[end]] =freq.get(s[end],0)+1
            while(freq[s[end]])>1:
                freq[s[st]]-=1
                st+=1
            length = max(length,end-st+1)
            end+=1
        return length