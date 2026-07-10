class Solution {
public:

    void down(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();

        while (i + 1 < n) {
            mat[i + 1][j] = 0;
            i++;
        }
    }

    void up(vector<vector<int>>& mat, int i, int j) {
        while (i - 1 >= 0) {
            mat[i - 1][j] = 0;
            i--;
        }
    }

    void right(vector<vector<int>>& mat, int i, int j) {
        int m = mat[0].size();

        while (j + 1 < m) {
            mat[i][j + 1] = 0;
            j++;
        }
    }

    void left(vector<vector<int>>& mat, int i, int j) {
        while (j - 1 >= 0) {
            mat[i][j - 1] = 0;
            j--;
        }
    }

    void setZeroes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans;

        // Store original zero indexes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    vector<int> temp;

                    temp.push_back(i);
                    temp.push_back(j);

                    ans.push_back(temp);
                }
            }
        }

        // Zero row and column
        for (int k = 0; k < ans.size(); k++) {

            int i = ans[k][0];
            int j = ans[k][1];

            down(mat, i, j);
            up(mat, i, j);
            right(mat, i, j);
            left(mat, i, j);
        }
    }
};