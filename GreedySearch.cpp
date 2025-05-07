#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define MAX 100

// Find the vertex with the minimum key not yet included in MST
int getMinKey(int key[], bool visited[], int n) {
    int minVal = INT_MAX, minIdx = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < minVal) {
            minVal = key[i];
            minIdx = i;
        }
    }
    return minIdx;
}

// Prim's algorithm to find MST
void primMST(int graph[MAX][MAX], int n) {
    int parent[n];     // Store MST structure
    int key[n];        // Store min weight edge
    bool visited[n];   // Track visited vertices

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;        // Start from node 0
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {
        int u = getMinKey(key, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Prim's MST:\nEdge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Dijkstra's algorithm for shortest path
void dijkstra(int graph[MAX][MAX], int n, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra's Shortest Path:\nNode \tDistance\n";
    for (int i = 0; i < n; i++) {
        cout << i << " \t" << dist[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int graph[MAX][MAX];
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int choice;
    cout << "\nChoose algorithm:\n";
    cout << "1. Prim's MST\n";
    cout << "2. Dijkstra's Shortest Path\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        primMST(graph, n);
    } else if (choice == 2) {
        int src;
        cout << "Enter source node: ";
        cin >> src;
        dijkstra(graph, n, src);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
