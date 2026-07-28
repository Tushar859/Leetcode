class Solution {
public:
    string largestOddNumber(string num) {
        int index= -1;
        for(int i=0;i<num.size();i++){

            int digit = num[i] -'0';
            if(digit%2!=0){
                index = i;
            }
        }
    if(index == -1){
        // no odd number found
        return "";
    }
    
else  {
 return num.substr(0,index+1);
}    
    
        
    }
};