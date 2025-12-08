#include<iostream>
#include<vector>
using namespace std;
class Edge {
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
    graph.push_back(Edge(0,1,2));
    graph.push_back(Edge(0,3,4));
    graph.push_back(Edge(1,2,10));
    graph.push_back(Edge(1,3,7));
    graph.push_back(Edge(2,3,9));
    graph.push_back(Edge(3,4,7));
}
void sortByWeight(vector<Edge> &edges)
{
    int n=edges.size();
    for (int i=0; i<n-1;i++)
    {
        for (int j=0;j<n-1-i;j++)
        {
            if (edges[j].weight>edges[j+1].weight)
            {
                Edge temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
}
int findParent(vector<int> &parent,int node)
{
    if (parent[node]==node)
        return node;
    return parent[node]=findParent(parent,parent[node]);
}
void unionSet(vector<int> &parent,vector<int> &rank,int u,int v)
{
    int pU=findParent(parent,u);
    int pV=findParent(parent,v);
    if (pU==pV)
        return;

    if (rank[pU]<rank[pV])
    parent[pU]=pV;

    else if (rank[pU]>rank[pV])
    parent[pV]=pU;
        
    else
    {
        parent[pV]=pU;
        rank[pU]++;
    }
}
void kruskal(vector<Edge> &edges, int vertex)
{
    sortByWeight(edges);
    vector<int> parent(vertex);
    vector<int> rank(vertex, 0);
    for (int i=0;i<vertex;i++)
        parent[i]=i;

    vector<Edge> mst;
    int totalWeight=0;

    for (auto &edge:edges)
    {
        int u=edge.source;
        int v=edge.dest;
        int pU=findParent(parent, u);
        int pV=findParent(parent, v);
        if (pU!=pV)
        {
            mst.push_back(edge);
            totalWeight+=edge.weight;
            unionSet(parent,rank,pU,pV);
        }
    }
    cout<<"Kruskal's Minimal Spanning Tree Edges:\n";
    for (auto &e:mst)
    cout<<e.source<<" to "<<e.dest<<" -> weight="<< e.weight<<endl;

    cout<<"Total weight of MST= "<<totalWeight<<endl;
}
int main() 
{
    int vertex=5;
    vector<Edge> graph;
    createGraph(graph);
    kruskal(graph,vertex);
    return 0;
}