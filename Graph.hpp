#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>
#include <stack>

class Graph {
public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int vertices);

    // Add an edge (u -> v)
    void addEdge(int u, int v);

    // Remove an edge (u -> v)
    void removeEdge(int u, int v);

    // Print the graph
    void printGraph() const;

    // Check if there is an edge between vertices u and v
    bool hasEdge(int u, int v);

    // Check if the graph is Eulerian
    bool isEulerian();

    // Print the Eulerian cycle
    void printEulerianCycle();

private:
    int numVertices;               // Number of vertices in the graph
    std::vector<std::list<int>> adj;  // Adjacency list for storing edges

    // DFS traversal to check connectivity
    void DFS(int v, std::vector<bool> &visited);
};

#endif // GRAPH_HPP