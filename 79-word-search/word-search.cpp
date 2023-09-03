class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int index = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(searchNext(board, word, i, j, m, n, index)){
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool searchNext(vector<vector<char>>& board, string word, int row, int col, int m, int n, int index){
        if(index == word.length()){
            return true;
        }
        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != 
        word[index] or board[row][col] == '!'){
            return false;
        }

        char c = board[row][col];
        board[row][col] = '!';

        // top direction
        bool top = searchNext(board, word, row - 1, col, m, n, index + 1);
        // right direction
        bool right = searchNext(board, word, row, col + 1, m, n, index + 1);
        // bottom direction
        bool bottom = searchNext(board, word, row + 1, col, m, n, index + 1);
        // left direction
        bool left = searchNext(board, word, row, col - 1, m, n, index + 1);


        board[row][col] = c;

        return top || bottom || left || right;

    }
};