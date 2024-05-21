#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_V = 1001;
const int MAX_E = 2001;

int V, E;
vector<pair<int, int>> edges[MAX_V];
int dist[MAX_V];

void bellmanFord(int source) {
    fill(dist, dist + V + 1, INF);
    dist[source] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (int u = 1; u <= V; ++u) {
            for (auto edge : edges[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 1; u <= V; ++u) {
        for (auto edge : edges[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative cycle\n";
                return;
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= V; ++i) {
        cout << "Shortest distance from node 1 to node " << i << ": ";
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}

int main() {
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[u].push_back({v, weight});
    }

    bellmanFord(1);

    return 0;
}
