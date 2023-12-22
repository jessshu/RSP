#include <iostream>

class Graph {
    private:
        std::vector<bool> visited; 
        std::vector<std::vector<int> > graph;

        int size = 10; 

    public:
        Graph() {
            visited.resize(size,false); 
            graph.resize(size); 
        }
        void addEdge(int src, int dest) {
            graph[src].push_back(dest); 
            graph[dest].push_back(src);
        };

        void DFS(int src) {
            visited[src] = true; 

            std::cout << src << " ";

            for (auto neighbour : graph[src]) {
                if (!visited[neighbour]) {
                    std::cout << "go back!" << std::endl;
                    DFS(neighbour);
                }
            }
        }
};

int main() {
/* Graph visualisation (1 as src) 
    6 - 1* 
       / \ 
  3 - 2   7
   \  |
     4 — 5

*/
Graph graph; 

graph.addEdge(6,1);
graph.addEdge(1,7);
graph.addEdge(1,2);
graph.addEdge(2,3);
graph.addEdge(2,4);
graph.addEdge(4,5);

graph.DFS(1); 

}