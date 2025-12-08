#include<iostream>
#include<queue>
#include<vector>
#include<climits>
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

void createGraph(vector<Edge> graph[]) 
{
    graph[0].push_back(Edge(0,1,11));
    graph[0].push_back(Edge(1,2,2));
    graph[1].push_back(Edge(1,0,1));
    graph[1].push_back(Edge(1,3,3));
    graph[1].push_back(Edge(2,3,10));
    graph[3].push_back(Edge(3,1,3));
    graph[2].push_back(Edge(2,0,7));
    graph[4].push_back(Edge(4,3,1));
}

void dijkstra(vector<Edge> graph[], int vertex, int source) 
{
    vector<int> dist(vertex, INT_MAX);
    dist[source]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});
    while (!pq.empty()) 
    {
        int current=pq.top().second;
        int curD=pq.top().first;
        pq.pop();
        if(curD>dist[current])
            continue;
        for (int i=0;i<graph[current].size();i++) 
        {
            Edge &edge=graph[current][i];
            int u=edge.source;
            int v=edge.dest;
            int w=edge.weight;

            if (dist[u]+w<dist[v]) 
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout << "Shortest Distance Path : "<<endl;
    for (int i=0;i<vertex;i++)
        cout<<source<<" to "<<i<<" -> "<<dist[i]<<endl;
}
int main() 
{
    int vertex=5;
    int source;
    vector<Edge> graph[vertex];
    cout<<"Enter source node: ";
    cin>>source;
    createGraph(graph);
    dijkstra(graph,vertex,source);
    return 0;
}