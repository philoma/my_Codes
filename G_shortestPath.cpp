#include <bits/stdc++.h>
void shortestpath(unordered_map<int, list<map<int, int>>> &adj, vector<int> &dist, stack<int> &topo, int src)
{
    dist[src] = 0;
    while (!topo.empty())
    {
        int top = topo.top();
        topo.pop();
        if (dist[top] != INT_MAX)
        {
            for (auto i : adj[top])
            {
                if (dist[top] + i.second < dis[i.first])
                {
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
}
void dfs(unordered_map<int, bool> &vis, unordered_map < int, stack<int> &topo, list<map<int, int>> &adj, int node)
{
    vid[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
            dfs(vis, s, adj, i);
    }
    topo.push(node);
}

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // Write your code here
    unordered_map<int, list<map<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    // topological sort
    unordered_map<int, bool> vis;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(vis, s, adj, i);
        }
    }

    // shortest path
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    shortestpath(adj, dist, st, s);
    return dist;
}
