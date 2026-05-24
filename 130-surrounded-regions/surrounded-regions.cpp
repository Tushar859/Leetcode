class Solution {
public:

    bool valid(int i, int j, int r, int c) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void solve(vector<vector<char>>& board) {

        int r = board.size();
        int c = board[0].size();

        queue<pair<int,int>> pq;

        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};

        for(int i=0; i<r; i++) {

            if(board[i][0] == 'O') {
                pq.push({i,0});
                board[i][0] = '#';
            }

            if(board[i][c-1] == 'O') {
                pq.push({i,c-1});
                board[i][c-1] = '#';
            }
        }


        for(int j=0; j<c; j++) {

            if(board[0][j] == 'O') {
                pq.push({0,j});
                board[0][j] = '#';
            }

            if(board[r-1][j] == 'O') {
                pq.push({r-1,j});
                board[r-1][j] = '#';
            }
        }

    
        while(!pq.empty()) {

            int i = pq.front().first;
            int j = pq.front().second;

            pq.pop();

            for(int k=0; k<4; k++) {

                int new_i = i + row[k];
                int new_j = j + col[k];

                if(valid(new_i,new_j,r,c) &&
                   board[new_i][new_j] == 'O') {

                    board[new_i][new_j] = '#';

                    pq.push({new_i,new_j});
                }
            }
        }

       
        for(int i=0; i<r; i++) {

            for(int j=0; j<c; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};