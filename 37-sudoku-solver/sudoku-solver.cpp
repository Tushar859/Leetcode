class Solution {
public:

    bool check(int i,int j,int num, vector<vector<char>>& board){

        char ch = '0' + num;

        // column
        for(int r=0;r<9;r++){
            if(board[r][j]==ch)
                return false;
        }

        // row
        for(int c=0;c<9;c++){
            if(board[i][c]==ch)
                return false;
        }

        // 3x3 block
        int row = (i/3)*3;
        int col = (j/3)*3;

        for(int r=row;r<row+3;r++){
            for(int c=col;c<col+3;c++){
                if(board[r][c]==ch)
                    return false;
            }
        }

        return true;
    }

    bool find(int i,int j, vector<vector<char>>& board){

        if(i==9)
            return true;

        if(j==9)
            return find(i+1,0,board);

        if(board[i][j] != '.')
            return find(i,j+1,board);

        for(int num=1; num<=9; num++){

            if(check(i,j,num,board)){

                board[i][j] = '0' + num;

                if(find(i,j+1,board))
                    return true;

                board[i][j] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        find(0,0,board);
    }
};