bool issafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    while (y >= 0)
    {
        if (board[x][y] == 1) // col ki us element se peeche wali poori row check ki
            return false;

        y--;
    }
    // 2nd quad type diagonal check kiya
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;

        x--;
        y--;
    }
    // 4th quad type diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void addsol(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{

    if (col == n)
    {
        addsol(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (issafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            // backtrack
            board[row][col]=0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    // Write your code here
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    // 0- col
    solve(0, ans, board, n);

    return ans;
}
