class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     int k = s1.length();
    int start =0,end=0;
    int n = s2.length();

    unordered_map<char,int>m;
      
    for(int i=0;i<k;i++){
        m[s1[i]]++;
    }
      int total = m.size();
    while(end<n){
     m[s2[end]]--;
     if(m[s2[end]]==0){
        total--;
     }
     // invalid 
     while(end-start+1>k){
        m[s2[start]]++;
         if (m[s2[start]] == 1)
            total++;
        start++;
     }
     // valid 
     if(end-start+1 == k && total==0){
        return true;
     }

    end++;

    }
     
 return false;


    }
};