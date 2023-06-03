#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    char source, destination;
    int weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
private:
    int numVertices;
    vector<Edge> edges;

public:
    Graph(int V) : numVertices(V) {}

    void addEdge(char source, char destination, int weight) {
        edges.push_back({source, destination, weight});
    }

    char findParent(vector<char>& parent, char vertex) {
        if (parent[vertex] == '\0')
            return vertex;
        return findParent(parent, parent[vertex]);
    }

    void unionSets(vector<char>& parent, char x, char y) {
        char xset = findParent(parent, x);
        char yset = findParent(parent, y);
        parent[xset] = yset;
    }

    void kruskalMST() {
        vector<Edge> result;
        vector<char> parent(numVertices, '\0');

        // Sort edges in non-decreasing order of their weight
        for (int i = 0; i < edges.size() - 1; i++) {
            for (int j = i + 1; j < edges.size(); j++) {
                if (edges[i].weight > edges[j].weight) {
                    swap(edges[i], edges[j]);
                }
            }
        }

        int i = 0, edgeCount = 0;
        while (edgeCount < numVertices - 1) {
            Edge nextEdge = edges[i++];
            char x = findParent(parent, nextEdge.source);
            char y = findParent(parent, nextEdge.destination);

            if (x != y) {
                result.push_back(nextEdge);
                unionSets(parent, x, y);
                edgeCount++;
            }
        }

        // Print the Minimum Spanning Tree
        cout << "Minimum Spanning Tree:" << endl;
        int totalWeight = 0;
        for (const Edge& edge : result) {
            cout << edge.source << " -- " << edge.destination << " : " << edge.weight << endl;
            totalWeight += edge.weight;
        }

        cout << "Total Weight: " << totalWeight << endl;
    }
};

int main() {
    int numVertices = 9;
    Graph graph(numVertices);

    graph.addEdge('A', 'B', 4);
    graph.addEdge('A', 'C', 2);
    graph.addEdge('B', 'C', 1);
    graph.addEdge('B', 'D', 5);
    graph.addEdge('C', 'D', 8);
    graph.addEdge('C', 'E', 10);
    graph.addEdge('D', 'E', 2);
    graph.addEdge('D', 'Z', 6);
    graph.addEdge('E', 'Z', 3);

    graph.kruskalMST();

    return 0;
}
