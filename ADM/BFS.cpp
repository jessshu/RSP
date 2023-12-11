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
#include <vector>

class Graph {
    protected:
        std::vector<std::vector<int> > graph; 

    public:
        Graph(int numNodes){
            int V = numNodes;
            graph.resize(V); 
        }; 

        void addEdge(int x, int y) { // assume undirected graph
            // store as neighbours in graph 
            graph[x].push_back(y); 
            graph[y].push_back(x); 
        }

        void BFS(int src) {
            int curr_node = src; 

            std::vector<int> queue; 
            std::vector<bool> discovered(graph.size(), false); 
            std::vector<bool> processed(graph.size()); 

            queue.push_back(src); 
            discovered[src] = true; 

            while(!queue.empty()) {
                // dequeue and print
                curr_node = queue.front(); 

                std::cout<< curr_node << " "; 
                queue.erase(queue.begin()); 
                

                for (int i = 0; i < graph[curr_node].size(); i++) {
                    int nbr = graph[curr_node][i]; 

                    if (discovered[nbr] == false) {
                        discovered[nbr] = true; 
                        queue.push_back(nbr);
                    }

                    
                }
            }
        }
};

int main() {
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(1,5);

    g.BFS(0);

}

