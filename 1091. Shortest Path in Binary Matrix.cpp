class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>>q;
        q.push({{0,0}, 1});
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1||grid[m-1][n-1]==1) return -1;
        if(grid[0][0]==0 && grid.size()==1 && grid[0].size()==1)return 1;

        vector<vector<bool>>vis(grid.size(),vector<bool>(grid.size(),false));
        vis[0][0]=1;


            while(!q.empty()){
                auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int path=it.second;
            vector<pair<int, int>> directions={{0,1}, {0,-1}, {1,0}, {-1,0},{1,1}, {-1,-1}, {1,-1}, {-1,1}};


            for(auto it:directions){
                int newx=x+it.first;
                int newy=y+it.second;

                if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]==0 && !vis[newx][newy]){
                    q.push({{newx, newy}, path+1});
                    vis[newx][newy]=1;

                    if(newx==grid.size()-1 && newy==grid[0].size()-1)
                     return path+1;
                }
            }
            }
        return -1;
    }
};



// https://leetcode.com/problems/shortest-path-in-binary-matrix/
