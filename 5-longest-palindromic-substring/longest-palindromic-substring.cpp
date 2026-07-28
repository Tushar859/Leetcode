class Solution {
public:
    string expand( string& str, int s, int e){

        while(s >= 0 && e< str.size() && str[s] == str[e]){
            s--;
            e++;
        }
        return str.substr(s+1, e-s-1);
        
    }
    string longestPalindrome(string s) {
        //  int ans = 0;
         string ans ="";
        for(int i =0; i<s.size() ; i++){
            string opt1 = expand( s, i, i);
            string opt2= "";
            if( i+1< s.size() && s[i] == s[i+1])
             opt2 = expand(s, i , i+1);
            
            cout<< opt1 <<" - "<< opt2<< " ;"<<endl;
            if(ans.size() < opt1.size()){
                ans = opt1;
            }
            if(ans.size() < opt2.size()){
                ans = opt2;
            }
        }
        return ans;
    }
};