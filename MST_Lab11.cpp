#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;
//Making the adjacency matrix
public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int source  , int destination, int weight) {
        adjMatrix[source][destination] = weight;
        adjMatrix[destination][source] = weight;
    }

    int findMinKey(vector<int>& key, vector<bool>& mstSet) {
        int minKey = INT_MAX, minIndex = -1;
        for (int v = 0; v < V; ++v) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    void printMST(vector<int>& parent) {
        cout << "Edge \tWeight\n";
        for (int v = 1; v < V; ++v) {
            cout << parent[v] << " - " << v << "\t" << adjMatrix[v][parent[v]] << "\n";
        }
    }

    void primMST(int startNode) {
        vector<int> key(V, INT_MAX);
        vector<bool> mstSet(V, false);
        vector<int> parent(V, -1);

        key[startNode] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = findMinKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        printMST(parent);
    }
};

int main() {
    int V = 6; // Number of vertices in the graph
    Graph g(V);

    // Add edges and weights to the graph
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 10);
    g.addEdge(0, 5, 1);
    g.addEdge(3, 1, 1);
    g.addEdge(2, 5, 5);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 5, 4);

    int startNode = 3;
    g.primMST(startNode);

    return 0;
}