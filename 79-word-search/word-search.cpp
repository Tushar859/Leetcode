class Solution {
public:
    int R, C;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    bool solve(int r, int c, int idx, vector<vector<char>>& board, string& word,
               vector<vector<bool>>& vis) {
        // All characters matched
        if (idx == word.size()) {
            return true;
        }
        // Boundary check
        if (r < 0 || r >= R || c < 0 || c >= C) {
            return false;
        }
        // Character mismatch or already visited
        if (board[r][c] != word[idx] || vis[r][c]) {
            return false;
        }
        // Mark visited
        vis[r][c] = true;
        // Explore 4 directions
        for (int k = 0; k < 4; k++) {
            int newR = r + row[k];
            int newC = c + col[k];
            if (solve(newR, newC, idx + 1, board, word, vis)) {
                return true;
            }
        }
        // Backtrack
        vis[r][c] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        R = board.size();
        C = board[0].size();
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
              // sare cell se check karenge like kitta matched hain
                if (solve(i, j, 0, board, word, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};