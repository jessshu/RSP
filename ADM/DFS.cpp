// time complexity: O(V+E) where v is numVertices and E is numEdges 

#include <iostream>
#include <map>

class Graph {
    protected:
        std::map<int,bool> discovered; 
        std::map<int,std::vector<int> > graph; 

    public:
        void addEdge(int src, int dest) {
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        };


        void DFS(int src) {
            discovered[src] = true; 

            std::cout << src << " "; 

            for (auto next : graph[src]) {
                if (discovered[next] == false) {
                    DFS(next); 
                }
            }

        }


};

int main() {
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,6);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.DFS(0); 

    return 0; 
}