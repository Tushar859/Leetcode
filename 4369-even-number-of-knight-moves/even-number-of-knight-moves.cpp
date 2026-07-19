class Solution {
public:
    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2};

    int dp[8][8][2];
    bool vis[8][8][2];

    bool dfs(int x, int y, int p, int tx, int ty) {
        if (x == tx && y == ty)
            return p == 0;

        if (vis[x][y][p])
            return dp[x][y][p];

        vis[x][y][p] = true;

        bool ans = false;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                ans |= dfs(nx, ny, p ^ 1, tx, ty);
            }
        }

        return dp[x][y][p] = ans;
    }

    bool canReach(vector<int>& start, vector<int>& target) {
        memset(vis, 0, sizeof(vis));
        return dfs(start[0], start[1], 0, target[0], target[1]);
    }
};