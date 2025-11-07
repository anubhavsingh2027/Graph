#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define INF 1e9

// ---------- BFS ----------
void bfs(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "\n";
}

// ---------- DFS ----------
void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited);
        }
    }
}

void dfs(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    cout << "\nDFS Traversal: ";
    dfsUtil(start, adj, visited);
    cout << "\n";
}

// ---------- Dijkstra ----------
void dijkstra(int start, vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currDist > dist[node]) continue;

        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "\nShortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << "\n";
    }
    cout << "\n";
}

// ---------- MAIN ----------
int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj_unweighted(n);
    vector<vector<pair<int, int>>> adj_weighted(n);

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v w) where w is weight (enter 0 if unweighted):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // For BFS & DFS (unweighted)
        adj_unweighted[u].push_back(v);
        adj_unweighted[v].push_back(u);

        // For Dijkstra (weighted)
        if (w == 0) w = 1; // Assume weight = 1 if unweighted
        adj_weighted[u].push_back({v, w});
        adj_weighted[v].push_back({u, w});
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    int choice;
    do {
        cout << "\n===== GRAPH ALGORITHMS MENU =====\n";
        cout << "1. Breadth First Search (BFS)\n";
        cout << "2. Depth First Search (DFS)\n";
        cout << "3. Dijkstra’s Shortest Path\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bfs(start, adj_unweighted, n);
                break;
            case 2:
                dfs(start, adj_unweighted, n);
                break;
            case 3:
                dijkstra(start, adj_weighted, n);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
//Anubhav Singh