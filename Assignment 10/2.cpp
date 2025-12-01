#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Link {
public:
    int u, v;
    Link(int a, int b) {
        u = a;
        v = b;
    }
};

void buildGraph(vector<Link> adj[], int n) {
    adj[0].push_back(Link(0, 1));
    adj[0].push_back(Link(0, 2));
    adj[1].push_back(Link(1, 3));
    adj[1].push_back(Link(1, 0));
    adj[2].push_back(Link(2, 4));
    adj[2].push_back(Link(2, 0));
    adj[3].push_back(Link(3, 1));
    adj[3].push_back(Link(3, 5));
    adj[3].push_back(Link(3, 4));
    adj[4].push_back(Link(4, 3));
    adj[4].push_back(Link(4, 5));
    adj[4].push_back(Link(4, 2));
    adj[5].push_back(Link(5, 6));
    adj[5].push_back(Link(5, 3));
    adj[5].push_back(Link(5, 4));
    adj[6].push_back(Link(6, 5));
}

void bfs(vector<Link> adj[], int nodes, vector<bool> &seen, int startNode) {
    queue<int> que;
    que.push(startNode);
    while (!que.empty()) {
        int top = que.front();
        que.pop();
        if (!seen[top]) {
            cout << top << " ";
            seen[top] = true;
            for (auto &e : adj[top]) {
                que.push(e.v);
            }
        }
    }
}
int main() {
    int n = 7;
    vector<Link> adjList[n];
    buildGraph(adjList, n);
    cout << "BFS Traversal: ";
    vector<bool> seen(n, false);
    for (int x = 0; x < n; x++) {
        if (!seen[x])
            bfs(adjList, n, seen, x);
    }
    cout << endl;
    return 0;
}
