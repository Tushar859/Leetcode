class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(m * n);
        int idx = 0;
        int row = 0;
        int col = 0;
        bool up = true;
        while (row < m && col < n) {
            if (up==true) {
                while (row > 0 && col < n - 1) {
                    ans[idx] = mat[row][col];
                    idx++;
                    row--;
                    col++;
                }
                // col = n-1 upar store ni ho rha to ise yha store krlo
                ans[idx] = mat[row][col];
                idx++;
                //edge case
                if (col == n - 1) {
                    row++;
                } else {
                    col++;
                }

            } else {
                while (row < m - 1 && col > 0) {
                    ans[idx] = mat[row][col];
                    idx++;
                    row++;
                    col--;
                }

                ans[idx] = mat[row][col];
                idx++;
                if (row == m - 1) {
                    col++;
                } else {
                    row++;
                }
            }

            up = !up;
        }

        return ans;
    }
};