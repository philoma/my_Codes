#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T> //ooper wali line k neeche hi likhna mandat he ye line


class graph{
    public:
 
    unordered_map<T, list<T>>adj;

    void addEdge(T u, T v, bool direction){
        // direction i.e. G is directed/ undirected

        //direction==0 undirected graph
        // direction ==1  directed graph

        adj[u].push_back(v);
        if(direction==0){  //undirected graph
            adj[v].push_back(u);
        }

    }

    void printAdjList(){
        for(auto it: adj){
            cout<<it.first<<"->";
            for(auto i:it.second){
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }

};

int main(){

    int n;
    cout<<"enter the num of noded/vertices\n";
    cin>>n;
    int m;
    cout<<"enter the num of edges \n";
    cin>>m;
    cout<<"enter the edges\n";
    // graph g;
    graph<int> g; //T dalne se generic data ka graph ban jaega, i.e. char wala graph hua to, int ki jagah char likhdo or bass hogaya 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdjList();

    return 0;
}
