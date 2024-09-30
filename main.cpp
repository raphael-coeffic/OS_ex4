#include "Graph.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <getopt.h>

using namespace std;

// Function to generate a random graph
void generateRandomGraph(Graph &g, int numVertices, int numEdges, unsigned int seed) {
    srand(seed);
    int u, v;
    for (int i = 0; i < numEdges; ++i) {
        do {
            u = rand() % numVertices;
            v = rand() % numVertices;
        } while (u == v || g.hasEdge(u, v)); // Avoid self-loops or duplicate edges
        g.addEdge(u, v);  // Add the edge to the graph
    }
}

int main(int argc, char *argv[]) {
    int opt;
    int numVertices = 0;
    int numEdges = 0;
    unsigned int seed = time(0);  // Default random seed based on current time

    // Use getopt to handle command-line arguments
    while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
            case 'v':
                numVertices = atoi(optarg);  // Get number of vertices from arguments
                break;
            case 'e':
                numEdges = atoi(optarg);  // Get number of edges from arguments
                break;
            case 's':
                seed = atoi(optarg);  // Get seed from arguments
                break;
            default:
                cerr << "Usage: " << argv[0] << " -v numVertices -e numEdges [-s seed]\n";
                return 0;
        }
    }

    // Parameter validation
    if (numVertices <= 0 || numEdges < 0 || numEdges > numVertices * (numVertices - 1) / 2) {
        cerr << "Invalid number of vertices or edges.\n";
        return 0;
    }

    // Create a graph with the specified number of vertices
    Graph g(numVertices);

    // Generate a random graph
    generateRandomGraph(g, numVertices, numEdges, seed);

    // Display the generated graph
    cout << "Generated Graph:\n";
    g.printGraph();

    // Run the Eulerian cycle algorithm
    g.printEulerianCycle();

    return 0;
}