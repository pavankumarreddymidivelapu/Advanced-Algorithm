#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

#define INF INT_MAX

typedef pair<int, int> iPair;

class Graph {
    int V; // No. of vertices
    list<pair<int, int> >* adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 

         {
        
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex Distance from Source:\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int V = 5;
    Graph g(V);

    int A = 0, B = 1, C = 2, D = 3, E = 4;

    g.addEdge(A, B, 10);
    g.addEdge(A, E, 3);
    g.addEdge(B, C, 2);
    g.addEdge(B, E, 4);
    g.addEdge(E, B, 1);
    g.addEdge(E, C, 8);
    g.addEdge(E, D, 2);
    g.addEdge(D, C, 7);
    g.addEdge(C, D, 9);

    g.shortestPath(0);

    return 0;
}
