class Solution {
public:
    int numberOfSubstrings(string str) {
      int n = str.size();
     unordered_map<char,int>m;
     int count =0;
      for(int i=0;i<n;i++){
          if(m[str[i]]==0){
              m[str[i]]++;
          }
      }
    
     int diff = m.size();
     if(diff<3){
        return 0;
     }
     int start=0,end=0;
     int len =INT_MAX;
     while(end<n){
        m[str[end]]--;
        if(m[str[end]]>=0){
            diff--;
        }
       
        while(diff==0 && start<=end){
            // count++;
            count += (n - end);
            m[str[start]]++;
            if(m[str[start]]>0){
                diff++;
            }
            start++;
            
        }
        
        end++;
         
     }
     return count;  
    }
};