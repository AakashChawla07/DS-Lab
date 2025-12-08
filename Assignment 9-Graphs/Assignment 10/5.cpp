#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
class Edge 
{
public:
    int source;
    int dest;
    int weight;
    Edge(int s,int d,int w) 
    {
        source=s;
        dest=d;
        weight=w;
    }
};

void createGraph(vector<Edge> &graph)
{
    graph.push_back(Edge(0,3,3));

    graph.push_back(Edge(0,2,2));
    graph.push_back(Edge(1,2,11));
    graph.push_back(Edge(1,3,7));
    graph.push_back(Edge(2,3,1));
    graph.push_back(Edge(3,4,2));
}
void prim(vector<Edge> &edges,int vertex)
{
    vector<vector<pair<int,int>>> adj(vertex);
    for (auto &e:edges)
    {
        adj[e.source].push_back({e.dest, e.weight});
        adj[e.dest].push_back({e.source, e.weight});
    }
    int start=0;
    vector<int> key(vertex,INT_MAX);
    vector<int> parent(vertex,-1);
    vector<bool> inMST(vertex,false); 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    key[start]=0;
    pq.push({0,start});
    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (inMST[u])
            continue; 

        inMST[u]=true;
        for (auto &p:adj[u])
        {
            int v=p.first;
            int wt=p.second;
            if (!inMST[v] && wt<key[v])
            {
                key[v]=wt;
                parent[v]=u;
                pq.push({key[v], v});
            }
        }
    }
    cout<<"Prim's MST edges:\n";
    int totalWeight=0;
    for (int v=0;v<vertex;v++)
    {
        if (parent[v]!=-1)
        {
            cout<<parent[v]<<" to "<<v<<" -> weight="<<key[v]<<endl;
            totalWeight+=key[v];
        }
    }
    cout<<"Total weight of MST="<<totalWeight<<endl;
}
int main() 
{
    int vertex=5;
    vector<Edge> graph;
    createGraph(graph);
    prim(graph,vertex);
    return 0;
}