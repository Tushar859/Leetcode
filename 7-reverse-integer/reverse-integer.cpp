class Solution {
public:
    void rev (string &num){
        int start =0;
        int end = num.size()-1;
        while(start<end){
            char temp = num[start];
            num[start]=num[end];
            num[end] = temp;
            start++;
            end--;
        }
    }
    int reverse(int x) {
       bool neg = false;
        string num = to_string(x);
         if (num[0] == '-') {
            neg = true;
            num.erase(0, 1);
        }
         rev(num);
        
        // lets remove leading zero
        // int i=0;
        // while(i<num.size()&&num[i]=='0'){
        //     i++;}


        //  if(i==num.size()){
        //     // iska mtlb sare zeros h
        //     return 0;
        //  } 
        
        // num = num.substr(i);
     
    long long ans = stoll(num);
     if(neg){
        ans = -ans;
     }
     // Overflow check
    if (ans > INT_MAX || ans < INT_MIN)
         return 0;




    return ans;
    
    }
};