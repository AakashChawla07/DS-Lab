#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int dest;
    Edge(int d) {
        dest = d;
    }
};
void addEdge(vector<Edge> graph[], int src, int dest) {
    graph[src].push_back(Edge(dest));
    graph[dest].push_back(Edge(src)); // For an undirected graph
}
void dfs(int node, vector<Edge> graph[], vector<bool> &visited) {
    cout << node << " ";
    visited[node] = true;

    for (auto &e : graph[node]) {
        if (!visited[e.dest]) {
            dfs(e.dest, graph, visited);
        }
    }
}

int main() {
    int vertices = 7;
    vector<Edge> graph[vertices];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    vector<bool> visited(vertices, false);
    cout << "DFS Traversal: ";
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
        }
    }
    cout << endl;
    return 0;
}
