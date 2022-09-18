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






















//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
   {
       // approach:
       // use set beacuse we need value with smallest ele when ele from set
       // create a set and a distance vector
       // make  srcnode distance =zero
       // and insert the entry in set ie. pair where first is distance and second is node
       //fetch top ie the mini distance value and remove it fromm set
       //explore its neighbours
       //check if its cur distance in dist vector is less then update 
       //else neglect
       //while(updating ) also check if that node/ i.second another is already pressnt or not
       // if present ,first the existing value then push new value
       //then push entry in set // do this until set is empty :)
       
       
       vector<int> dist(V);
       for(int i=0;i<V;i++)
           dist[i]=INT_MAX;
       set<pair<int,int>> st;
       dist[S]=0;
       st.insert({0,S});
       while(!st.empty()){
           auto top=*(st.begin());//get top/first ele
           int nodeDist=top.first;
           int topnode=top.second;
           st.erase(st.begin());// because stored in sorted order
       
           for(auto nei:adj[topnode]){
          
               if(nodeDist+nei[1]<dist[nei[0]]){
                 auto record=st.find(make_pair(dist[nei[0]],nei[0]));
                 //if record already found // then erase
                 if(record!=st.end()){
                     st.erase(record); // delete already existing value
                 }
                 //now update 
                 dist[nei[0]]=nodeDist+nei[1];
                 
                 //push record in set
                 st.insert({dist[nei[0]],nei[0]});
               }
           }   
       }   
       return dist;
   }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
