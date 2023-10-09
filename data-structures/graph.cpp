#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V; 
    Graph(int V); 
    void addEdge(int u, int v, int weight = 1); 
    void printGraph(); 
private:
    vector<vector<pair<int, int>>> adjacencyList; 
    vector<vector<int>> adjacencyMatrix; 
};

Graph::Graph(int V) {
    this->V = V;
    adjacencyList.resize(V);
	adjacencyMatrix.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int u, int v, int weight) {
    adjacencyList[u].push_back({v, weight});
    adjacencyList[v].push_back({u, weight});

    adjacencyMatrix[u][v] = weight;
    adjacencyMatrix[v][u] = weight;
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (const auto& neighbor : adjacencyList[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }

	cout << "Adjacency matrix:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4; 
    Graph graph(V);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 4);

    graph.printGraph();
}
