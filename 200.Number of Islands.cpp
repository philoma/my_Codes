class Solution {
private:
  
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        
            
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                    int nrow = row+dx[i];
                    int ncol = col +dy[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                        dfs(nrow, ncol, visited, grid);
                    }
                }
            }
        
  public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]  && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};



// https://leetcode.com/problems/number-of-islands/
//https://www.youtube.com/watch?v=__98uL6wst8&t=57s
