// breadth first search:
//searches all neighbours 

/* General steps:
1. create queue and mark source vertex as discovered 
2. add starting node to queue
3. while queue is NOT empty: 
    a. remove first node from queue
    b. explore all neighbours of current node (iterate through)
    c. mark undiscovered neighbours as discovered and add to queue*/

#include <iostream>

class Graph {
    private: 
        std::vector<bool> visited; 
        std::vector<bool> processed;
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

        void BFS(int src) {
            std::vector<int> queue; 

            queue.push_back(src); 
            visited[src] = true; 

            while (!queue.empty()) {
                int curr = queue.front();
                std::cout << curr << " ";
                queue.erase(queue.begin()); 

                for (auto neighbour : graph[src]) {
                    if (!visited[neighbour]) {
                        queue.push_back(neighbour);
                        visited[neighbour] = true; 
                    }

                }
            }

            std::cout << std::endl; 
        }

};

int main() {
    Graph g; 

    g.addEdge(1,6);
    g.addEdge(1,7); 
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.BFS(1); 
}




