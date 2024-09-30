#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// Constructor to initialize the graph with a given number of vertices
Graph::Graph(int vertices) {
    numVertices = vertices;
    adj.resize(vertices);  // Resize the adjacency list
}

// Function to add an edge (u -> v)
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // If the graph is undirected
}

// Function to remove an edge (u -> v)
void Graph::removeEdge(int u, int v) {
    adj[u].remove(v);
    adj[v].remove(u);  // If the graph is undirected
}

// Depth First Search (DFS) function to check connectivity
void Graph::DFS(int v, vector<bool> &visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(u, visited);  // Recursive DFS call
        }
    }
}

// Function to check if an edge exists between vertices u and v
bool Graph::hasEdge(int u, int v) {
    for (int neighbor : adj[u]) {
        if (neighbor == v) return true;  // Edge found
    }
    return false;  // No edge found
}

// Function to check if the graph is Eulerian
bool Graph::isEulerian() {
    // Check connectivity
    vector<bool> visited(numVertices, false);

    // Find a start vertex with edges
    int startVertex = -1;
    for (int i = 0; i < numVertices; i++) {
        if (!adj[i].empty()) {
            startVertex = i;
            break;
        }
    }
    if (startVertex == -1) {
        cout << "No edges in the graph." << endl;
        return false;  // Graph has no edges
    }

    // Run DFS to check connectivity from startVertex
    DFS(startVertex, visited);

    // If any vertex is not visited but has edges, the graph is not connected
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && !adj[i].empty()) {
            cout << "Graph is not connected." << endl;
            return false;
        }
    }

    // Check if all vertices have even degrees
    for (int i = 0; i < numVertices; i++) {
        if (adj[i].size() % 2 != 0) {
            cout << "Found Odd Degree at Vertex " << i << endl;
            return false;  // Odd degree vertex found
        }
    }

    return true;  // Graph is Eulerian
}

// Function to print the Eulerian cycle
void Graph::printEulerianCycle() {
    if (!isEulerian()) {
        cout << "Graph is not Eulerian\n";
        return;
    }

    stack<int> curr_path;
    vector<int> circuit;

    // Use a stack to store the current path
    int curr_v = 0;
    curr_path.push(curr_v);

    // While the current path is not empty
    while (!curr_path.empty()) {
        if (!adj[curr_v].empty()) {
            curr_path.push(curr_v);

            // Take the first available edge
            int next_v = adj[curr_v].front();

            // Remove the edge from the graph
            removeEdge(curr_v, next_v);

            curr_v = next_v;
        } else {
            // Add vertex to the Eulerian circuit
            circuit.push_back(curr_v);

            // Go back to the previous vertex
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }

    // Print the Eulerian circuit
    cout << "Eulerian Circuit: ";
    for (int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i];
        if (i > 0) {
            cout << " -> ";
        }
    }
    cout << endl;
}

// Function to print the graph's adjacency list
void Graph::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ":";
        for (int v : adj[i]) {
            cout << " -> " << v;
        }
        cout << endl;
    }
}