class Solution {
public:
    int R;
    int C;
    int row[4] = {-1, 0, 0, 1};
    int col[4] = {0, -1, 1, 0};
    bool valid(int r, int c) {
        return (r >= 0 && r < R && c >= 0 && c < C);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       R = grid.size();
        C = grid[0].size();
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(grid[i][j] == 1) {

                    int cnt = 0;

                    q.push({i, j});
                    grid[i][j] = 0;

                    while(!q.empty()) {

                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        cnt++;

                        for(int k = 0; k < 4; k++) {

                            int r = x + row[k];
                            int c = y + col[k];

                            if(valid(r, c) && grid[r][c] == 1) {

                                grid[r][c] = 0;
                                q.push({r, c});
                            }
                        }
                    }

                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};