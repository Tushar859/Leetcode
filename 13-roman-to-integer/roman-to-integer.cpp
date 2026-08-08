class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
    unordered_map<char,int>m;
     // define reln of 
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int sum=0;
        int index =0;
        while(index<s.size()-1){
            if(m[s[index]]<m[s[index+1]]){
                sum-=m[s[index]];
            }
            else{
                sum+=m[s[index]];
            }
         index++;

        }
        // last char ko add krdo
         sum +=m[s[n-1]];
     return sum;

    }
};