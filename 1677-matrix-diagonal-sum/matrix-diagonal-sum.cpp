class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<bool>> flag(n, vector<bool>(n, false));
        int  diag1=0,diag2=0;
        for(int i=0;i<mat.size();i++){
            if(flag[i][i]==false){
                diag1+=mat[i][i];
                flag[i][i] = true;
            }
         if(!flag[i][n-i-1])
            diag2+= mat[i][n-i-1];
            flag[i][n-i-1]=true;
           
        }

     return (diag2+diag1);
    }
};