class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // phele transpose krlo phr reverse krdo col se
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
       for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
     int n = mat.size();
     // 4 baar iss liye kar rhre hain kiuki uske baad phr matrix original bn jayegi apne aap
     for(int i =0;i<4;i++){
         if(mat == target)
            return true;
         rotate(mat);
        }
        
        return false;
    }
};