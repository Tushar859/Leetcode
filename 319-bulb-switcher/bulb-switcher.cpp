class Solution {
public:
    int bulbSwitch(int n) {
      int count =0;
      //perfect sq count kr re h
      for(int i =1; i*i<=n;i++){
        count++;
      }
      return count;
    }
};
