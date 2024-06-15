#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

void addEdge(vector<vector<pair<int, int> > >& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

void primMST(const vector<vector<pair<int, int> > >& graph, int V, int& total_steps) {
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int src = 0; // Start from vertex 0

    key[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        total_steps++; // Increment steps for selecting vertex u

        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print MST edges and their weights
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << key[i] << endl;
    }
}

int main() {
    const int V = 5;
    vector<vector<pair<int, int> > > graph(V);

    // Adding edges to the graph
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 1, 2);
    addEdge(graph, 0, 3, 8);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 0, 3, 7);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 2, 1, 9);

    int total_steps = 0; // Initialize total steps counter

    primMST(graph, V, total_steps);

    cout << "Total number of steps: " << total_steps << endl; // Print total steps

    return 0;
}



