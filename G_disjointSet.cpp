void makeset(vector<int> &parent,
             vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// finding parent and path compression
int findparent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);
}
void unionset(int u, int v, vector<int> &parent)
{
    u = findparent(parent, u);
    v = findparent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int go(vector<vector<int>> &edges, int n)
{
    /*
      Don't write main().
      Don't read input, it is passed as function argument.
      No need to print anything.
      Taking input and printing output is handled automatically.
    */
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank);
  
  //link: https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
}
