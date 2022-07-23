bool issafe(int newx, int newy, vector < vector < int >> & arr,vector<vector<bool>>&vis, int n ){
    if((newx>=0 && newy<n) &&(newy>=0 && newx < n)&& vis[newx][newy]==0 && arr[newx][newy]==1){
        return true;
    }else{
        return false;
    }
}


void solve(int x, int y,vector < vector < int >> & arr, int n, vector<string>&ans, vector<vector<bool>>&vis,string path){
    //base case:
    if(x==n-1 &&y==n-1) {
        ans.push_back(path);
        return;
    }
    //4 movements D L R U
    
    //down:
    if(issafe(x+1,y,arr, vis, n)){
        vis[x][y]=1;
        solve(x+1,y,arr,n, ans, vis ,path+'D');
        
    }
    
    //left
    if(issafe(x,y-1,arr, vis, n)){
        vis[x][y]=1;
        solve(x,y-1,arr,n, ans, vis ,path+'L');
    
    }
    
    //right
    
    if(issafe(x,y+1,arr, vis, n)){
        vis[x][y]=1;
        solve(x,y+1,arr,n, ans, vis ,path+'R');

    }
    
    //up
    
    if(issafe(x-1,y,arr, vis, n)){
        vis[x][y]=1;
        solve(x-1,y,arr,n, ans, vis ,path+'U');
   
    }
    vis[x][y]=0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0) return ans;
    solve(0,0,arr,n, ans,visited,path);
    return ans;
  //link: https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
}
