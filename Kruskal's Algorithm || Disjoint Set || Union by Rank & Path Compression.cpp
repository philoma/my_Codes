#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2]; // comparator func jisse cheeze(wt) khud asc order me sort ho jaenge, include algo header bro
}

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
void unionset(int u, int v, vector<int> &parent, vector<int>&rank)
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
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    /*
      Don't write main().
      Don't read input, it is passed as function argument.
      No need to print anything.
      Taking input and printing output is handled automatically.
    */
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);
    int minwt = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findparent(parent, edges[i][0]);
        int v = findparent(parent, edges[i][1]);
        if (u != v)
        {
            minwt += edges[i][2];
            unionset(u, v, parent, rank);
        }
    }
    return minwt;
  
  //link:  https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
}
