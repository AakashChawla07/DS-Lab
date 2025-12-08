#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // number of vertices
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix = vector<vector<int>>(V, vector<int>(V, 0));
        adjList = vector<vector<int>>(V);
    }

    void addEdge(int src, int dest, bool directed = false) {
        adjMatrix[src][dest] = 1;
        adjList[src].push_back(dest);

        if (!directed) { 
            adjMatrix[dest][src] = 1;
            adjList[dest].push_back(src);
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j : adjList[i])
                cout << j << " ";
            cout << endl;
        }
    }

    int degree(int vertex) {
        return adjList[vertex].size();
    }

    int inDegree(int vertex) {
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (adjMatrix[i][vertex] == 1)
                count++;
        }
        return count;
    }

    int outDegree(int vertex) {
        return adjList[vertex].size();
    }

    void adjacentVertices(int vertex) {
        cout << "Adjacent vertices of " << vertex << ": ";
        for (int v : adjList[vertex])
            cout << v << " ";
        cout << endl;
    }

    int countEdges(bool directed = false) {
        int edges = 0;
        for (int i = 0; i < V; i++)
            edges += adjList[i].size();

        if (!directed)
            edges /= 2;
        return edges;
    }
};

int main() {
    int V = 6; // number of vertices
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.displayAdjMatrix();
    g.displayAdjList();

    cout << "\nDegree of vertex 3: " << g.degree(3) << endl;
    cout << "In-Degree of vertex 3: " << g.inDegree(3) << endl;
    cout << "Out-Degree of vertex 3: " << g.outDegree(3) << endl;

    g.adjacentVertices(3);

    cout << "Total number of edges: " << g.countEdges(false) << endl;

    return 0;
}
