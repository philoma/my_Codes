void dfs(unordered_map<int, list<int>>&adj, unordered_map<int, bool>&visited,vector<int>&component,int node){
    component.push_back(node);
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
   dfs(adj, visited, component, i);
   }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    unordered_map<int, bool>visited;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(adj, visited,component, i);
            ans.push_back(component);
        }
    }
  //link: https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
    return ans;
}
