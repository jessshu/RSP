#include <iostream>

// class Graph {

//   private:
//     int numVertices;
//     std::list<int> *lists; // array containing adjacency lists 

//  public:
//   Graph(int vertices);

//   void addEdge(std::vector<int> adj[], int s, int d){
//     adj[s].push_back(d); 
//     adj[d].push_back(s); 
//   };

//   void printGraph(std::vector<int> adj[], int vertices) {
//     for (int i = 1; i < vertices; i++) {
//         std::cout << "\n Vertex " << i << ":";
//         for (auto x : adj[i]) {
//             std::cout << "->" << x << std::endl; 
//         }
//     }
//   }

// };

using namespace std;

// Add edge
void addEdge(vector<int> adj[], int src, int dest) {
    // need to add vertices to arrays for neighbouring vertices (goes both ways since assumed UNDIRECTED graph)
  adj[src].push_back(dest); // add d into neighbouring vertices of s 
  adj[dest].push_back(src); // add s into neighbouring vertices of d  
}

// Print the graph
void printGraph(std::vector<int> graph[], int numVertices) {
    for (int i = 0; i < numVertices-1; i++) {
        std::cout << "graph[" << i << "] : " ;
        for (int j = 0; j < graph[i].size(); j++) {
            std::cout << graph[i][j] << ", ";
        }

        std::cout << std::endl; 
    }
}

int main() {
  int V = 5;

  // Create a graph
  vector<int> adj[V];

  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V);
}

