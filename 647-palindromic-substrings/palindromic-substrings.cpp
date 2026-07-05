class Solution {
public:
    int validPalindrome(string s, int i, int j){
        int count =0;
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            count++;
           
            i--;
            j++;
        

        }
    return count;
        
    }
    int countSubstrings(string s) {
     int count=0;
     for(int centre =0;centre<s.length();centre++){
        // phele odd palindrome check krenge 
        // isme i aur j same pe rhenge
        int i = centre;
        int j= centre;
        int oddPalindromeCount = validPalindrome(s,i,j);
        // ab odd palindrome hp gya even ke liye 
        // isme i aur j ek aage pheche
         i = centre;
         j= centre+1;
         int evenPalindromeCount = validPalindrome(s,i,j);
         count+=evenPalindromeCount+oddPalindromeCount;
     }
    return count;
    }
};