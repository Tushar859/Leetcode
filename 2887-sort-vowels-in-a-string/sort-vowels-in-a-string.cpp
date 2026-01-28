class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>>pq;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o' || s[i]=='i'|| s[i]=='u'){
                pq.push(s[i]);
            }

            if(s[i]=='A'||s[i]=='E'||s[i]=='O' || s[i]=='I'|| s[i]=='U'){
                pq.push(s[i]);
            }

        }
            string ans;
       
             for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o' || s[i]=='i'|| s[i]=='u'){
               char val = pq.top();  
                  pq.pop();             

               ans+=val;
            }

            else if(s[i]=='A'||s[i]=='E'||s[i]=='O' || s[i]=='I'|| s[i]=='U'){
                  char val = pq.top();  
                  pq.pop(); 


               ans+=val;
            }
            else{
                    ans+=s[i];
            }
         

        }


        return ans;


    }
};