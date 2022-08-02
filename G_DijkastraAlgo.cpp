#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int src)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(v);
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
//set (distance, node)
    set<pair<int, int>> st;
    dist[src] = 0;
    st.insert({0, src});
    while (!st.empty())
    {
        // top element
        auto top = *(st.begin());
        st.erase(st.begin());
        for (auto neighbour : adj[top.second])
        {
            if (top.first + neighbour.second < dist[neighbour.first])
            {

                auto record = st.find({dist[neighbour.first], neighbour.first});

                                  if (record != st.end()){
                                      st.erase(record);} 
                dist[neighbour.first] = top.first + neighbour.second;

                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }

    return dist;
}
// link: https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
